/*
  ==============================================================================

    ButtonFlatView.cpp
    Created: 27 Feb 2024 6:35:24pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "button-flat-view.h"

//==============================================================================
ButtonFlatView::ButtonFlatView(std::string label, std::function<void()> call, juce::Colour backing, juce::Colour face)
{
    // Sets up the button label.
    button.setButtonText(label);

    // Sets up the button call.
    button.onClick = call;

    // Styles the button.
    button.setLookAndFeel(&lookAndFeel);
    button.getLookAndFeel().setColour(juce::TextButton::buttonColourId, backing);
    button.getLookAndFeel().setColour(juce::ComboBox::outlineColourId, backing);
    button.getLookAndFeel().setColour(juce::TextButton::textColourOffId, face);
    button.changeWidthToFitText();

    // Makes the button visible.
    addAndMakeVisible(button);
}

ButtonFlatView::~ButtonFlatView()
{
    button.setLookAndFeel(nullptr);
}

void ButtonFlatView::paint(juce::Graphics& g)
{
}

void ButtonFlatView::resized()
{
    int size = STYLE_SIZE_FLAT_BUTTON;
    int halfSize = size / 2;
    button.setBounds(getWidth() / 2 - halfSize, getHeight() / 2 - halfSize, size, size);
}

void ButtonFlatView::setButtonText(std::string label)
{
    button.setButtonText(label);
}
