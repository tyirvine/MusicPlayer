/*
  ==============================================================================

    MixerTableView.h
    Created: 27 Feb 2024 6:43:39pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MixerTableView  : public juce::Component
{
public:
    MixerTableView();
    ~MixerTableView() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerTableView)
};
