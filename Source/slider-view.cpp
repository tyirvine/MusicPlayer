/*
  ==============================================================================

    SliderView.cpp
    Created: 3 Mar 2024 7:05:05pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include <sstream>
#include "slider-view.h"

//==============================================================================
SliderView::SliderView(SliderType sliderType, std::function<void(float value)> listener, std::string label, float* leftValue, float* rightValue)
    : sliderType(sliderType)
    , label(label)
    , leftValue(leftValue)
    , rightValue(rightValue)
    , isBeingDragged(false)
{
    // Assign the look and feel based on the slider type.
    // As well as any default slider settings.
    switch (sliderType) {
    case SliderType::UniDirectional:
        lookAndFeel = &sliderUniLookAndFeel;
        break;

    case SliderType::BiDirectional:
        lookAndFeel = &sliderBiLookAndFeel;
        slider.setValue(5.0);
        break;

    case SliderType::BiDirectionalVertical:
        lookAndFeel = &sliderBiVerticalLookAndFeel;
        slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
        slider.setValue(5.0);
        break;

    case SliderType::UniDirectionalProgress:
        lookAndFeel = &sliderUniProgressLookAndFeel;
        break;

    default:
        break;
    }

    // Setup the drag listeners.
    slider.onDragStart = [=] {
        isBeingDragged = true;
    };
    slider.onDragEnd = [=] {
        isBeingDragged = false;
    };

    // Setup the listener.
    slider.onValueChange = [=] {
        // Grab the new value and store it based on its slider type.
        if (sliderType == SliderType::UniDirectional || sliderType == SliderType::UniDirectionalProgress) {
            value = slider.getValue() / 10.0f;
        } else {
            value = (slider.getValue() - 5.0f) / 5.0f;
        }

        // Call the listener here only when the slider is being dragged.
        if (isBeingDragged) {
            listener(value);
        }
    };

    // Setup the styling for the slider.
    slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    slider.setLookAndFeel(&(*lookAndFeel));

    // Make the slider visible.
    addAndMakeVisible(slider);
}

SliderView::~SliderView()
{
}

void SliderView::paint(juce::Graphics& g)
{
#if DEBUG
    // This is just so we can debug the padding around the slider views.
//    g.fillAll(juce::Colour(0, 127, 0));
#endif
}

void SliderView::paintOverChildren(juce::Graphics& g)
{
    // Setup the slider label styling.
    int textPaddingX = 14;
    int textWidth = getWidth() - (textPaddingX * 2);
    int textPaddingY = 10;
    int textHeight = getHeight() - (textPaddingY * 2);
    juce::Font font = CustomFonts::fontSFProBold(15);
    g.setFont(font);

    // Draw the labels based on the slider type.
    switch (sliderType) {
    case SliderType::UniDirectional:
        g.setColour(STYLE_COLOR_SLIDER_UNI_SECONDARY);
        g.drawText(label, textPaddingX, 0, textWidth, getHeight(), juce::Justification::left);
        g.drawText(std::to_string(int(std::trunc(value * 100))) + "%", textPaddingX, 0, textWidth, getHeight(), juce::Justification::right);
        break;

    case SliderType::BiDirectional:
        g.setColour(STYLE_COLOR_SLIDER_BI_SECONDARY);
        g.drawText(label, textPaddingX, 0, textWidth, getHeight(), juce::Justification::left);
        // Reference available in the report. [8]
        // https://stackoverflow.com/a/29200671/13142325
        g.drawText((std::stringstream {} << std::fixed << std::setprecision(2) << value).str(), textPaddingX, 0, textWidth, getHeight(), juce::Justification::right);
        break;

    case SliderType::BiDirectionalVertical:
        g.setColour(STYLE_COLOR_SLIDER_BI_SECONDARY);
        // Sets up the top text label.
        g.setFont(CustomFonts::fontSFProBold(13));
        g.saveState();
        // There had to be a lot of manual adjustments added to get the labels to sit correctly.
        g.addTransform(juce::AffineTransform::rotation(1.57, getWidth() / 2, textPaddingY + 12));
        g.drawText(label, 0, textPaddingY + 6, getWidth(), textHeight, juce::Justification::centredTop);
        g.restoreState();
        // Sets up the bottom value label.
        g.setFont(CustomFonts::fontSFProBold(12));
        g.drawText((std::stringstream {} << std::fixed << std::setprecision(1) << value).str(), 0, textPaddingY, getWidth(), textHeight, juce::Justification::centredBottom);
        break;

    case SliderType::UniDirectionalProgress:
        // Only draw these labels if they're being filled.
        if (*leftValue == 0.0f && *rightValue == 0.0f) {
            break;
        }

        g.setColour(STYLE_COLOR_SLIDER_BI_SECONDARY);
        // Draw the left value formatted as a timestamp.
        g.drawText(formatTimeValue(*leftValue), textPaddingX, 0, textWidth, getHeight(), juce::Justification::left);
        // Draw the right value formatted as a timestamp.
        g.drawText(formatTimeValue(*rightValue), textPaddingX, 0, textWidth, getHeight(), juce::Justification::right);
        break;

    default:
        break;
    }
}

void SliderView::resized()
{
    // We have to add in a negative margin to pull the slider range into the bounds.
    int sliderMargin = 12;

    // We have to add the slider margin based on the orientation of the slider.
    if (sliderType == SliderType::BiDirectionalVertical) {
        slider.setBounds(0, sliderMargin * -1, getWidth(), getHeight() + sliderMargin * 2);
    } else {
        slider.setBounds(sliderMargin * -1, 0, getWidth() + sliderMargin * 2, getHeight());
    }
}

std::string SliderView::formatTimeValue(int seconds)
{
    // Here we grab the individual seconds and minutes units of a M:SS song time format.
    int secondsFormatted = seconds % 60;
    int minutesFormatted = floor(seconds / 60);

    std::string secondsFill = (secondsFormatted < 10) ? "0" : "";
    return std::to_string(minutesFormatted) + ":" + secondsFill + std::to_string(secondsFormatted);
}
