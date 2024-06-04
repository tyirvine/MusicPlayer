/*
  ==============================================================================

    SearchRaisedView.h
    Created: 27 Feb 2024 6:38:34pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "styles.h"

//==============================================================================
/*
*/
class SearchRaisedView : public juce::Component {
public:
    SearchRaisedView(std::function<void()> listener);

    ~SearchRaisedView() override;

    void paint(juce::Graphics&) override;

    void resized() override;
	
	std::string getText();

private:
    juce::TextEditor textEditor {};

    SearchLookAndFeel lookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SearchRaisedView)
};
