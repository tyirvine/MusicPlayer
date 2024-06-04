/*
  ==============================================================================

    WaveformDisplay.h
    Created: 1 Feb 2024 9:39:53am
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MixerChannelView : public juce::Component {
public:
    MixerChannelView(juce::AudioFormatManager& formatManagerToUse, juce::AudioThumbnailCache& cacheToUse);

    ~MixerChannelView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void loadURL(juce::URL audioURL);

    void setPositionRelative(double pos);

private:
    juce::AudioThumbnail audioThumb;

    bool fileLoaded;

    double position;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MixerChannelView)
};
