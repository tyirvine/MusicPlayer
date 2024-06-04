/*
  ==============================================================================

    CustomTextButton.h
    Created: 9 Mar 2024 11:53:20pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class CustomTextButton : public juce::TextButton {
public:
    CustomTextButton();

    void paintButton(juce::Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

private:
	
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomTextButton)
};
