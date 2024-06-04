/*
  ==============================================================================

    MixingManager.h
    Created: 27 Feb 2024 7:03:29pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "deck-controller.h"

//==============================================================================
/*
*/
class MixingManager : public juce::AudioAppComponent {
public:
    MixingManager(juce::AudioFormatManager& formatManagerReference, std::vector<std::unique_ptr<DeckController>>& decks);

    ~MixingManager() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;

    void releaseResources() override;

private:
    juce::AudioFormatManager& formatManager;

    std::vector<std::unique_ptr<DeckController>>& decks;

    juce::AudioThumbnailCache thumbCache { 100 };

    juce::MixerAudioSource mixerSource;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MixingManager)
};
