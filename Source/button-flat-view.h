/*
  ==============================================================================

    ButtonFlatView.h
    Created: 27 Feb 2024 6:35:24pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "styles.h"
#include "custom-text-button.h"

//==============================================================================
/// Represents a button without any border. It has a flat appearance.
class ButtonFlatView : public juce::Component {
public:
    ButtonFlatView(std::string label, std::function<void()> call, juce::Colour backing = STYLE_COLOR_BACKING_PRIMARY, juce::Colour face = STYLE_COLOR_FLAT_TEXT);

    ~ButtonFlatView() override;

    void paint(juce::Graphics&) override;
	
    void resized() override;
	
	void setButtonText(std::string label);

private:
    CustomTextButton button {};

    SFProMediumLookAndFeel lookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonFlatView)
};
