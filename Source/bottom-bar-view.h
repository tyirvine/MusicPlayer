/*
  ==============================================================================

    BottomBarView.h
    Created: 27 Feb 2024 6:39:02pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/// This represents a bottom bar of a view. This was made a universal view so that
/// all bottom bars formed a consistent appearance.
class BottomBarView : public juce::Component {
public:
    /// It's optional to pass in a button in the form of a pointer.
    /// If nothing meaningful is passed in then the buttons will simply not be displayed.
    BottomBarView(std::string label, juce::Colour backingColor, juce::Colour dividerColor, juce::Colour textColor, juce::Button* rightButton = nullptr, juce::Button* leftButton = nullptr);

    ~BottomBarView() override;

    void paint(juce::Graphics&) override;

    void resized() override;
	
	void update(std::string label);

private:
    std::string label;

    juce::Colour backingColor;

    juce::Colour dividerColor;

    juce::Colour textColor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BottomBarView)
};
