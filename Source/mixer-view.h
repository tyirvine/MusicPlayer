/*
  ==============================================================================

    MixerView.h
    Created: 27 Feb 2024 6:42:08pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MixerView  : public juce::Component
{
public:
    MixerView();
    ~MixerView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerView)
};
