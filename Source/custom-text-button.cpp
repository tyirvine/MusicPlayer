/*
  ==============================================================================

    CustomTextButton.cpp
    Created: 9 Mar 2024 11:53:20pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "custom-text-button.h"
#include "styles.h"

//==============================================================================
CustomTextButton::CustomTextButton()
{
}

void CustomTextButton::paintButton(juce::Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    // Draw the button background.
    if (shouldDrawButtonAsHighlighted) {
        g.setColour(juce::Colour(juce::uint8(255), juce::uint8(255), juce::uint8(255), 0.08f));
        g.fillRoundedRectangle(0, 0, getWidth(), getHeight(), 6.0f);
	}
	
	if (shouldDrawButtonAsDown) {
		g.setColour(juce::Colour(juce::uint8(255), juce::uint8(255), juce::uint8(255), 0.06f));
		g.fillRoundedRectangle(0, 0, getWidth(), getHeight(), 6.0f);
	}

    // Draw the button text.
    g.setColour(getLookAndFeel().findColour(juce::TextButton::ColourIds::textColourOffId));
    g.setFont(CustomFonts::fontSFProMedium(16));
    g.drawText(getButtonText(), 0, 0, getWidth(), getHeight(), juce::Justification::centred);
}
