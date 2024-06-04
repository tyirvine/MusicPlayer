/*
  ==============================================================================

    AudioLevelView.h
    Created: 27 Feb 2024 6:39:26pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/// This displays the audio levels of a provided song.
class AudioLevelView : public juce::Component {
public:
    AudioLevelView();
    ~AudioLevelView() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioLevelView)
};
