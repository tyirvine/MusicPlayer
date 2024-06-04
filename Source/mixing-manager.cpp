/*
  ==============================================================================

    MixingManager.cpp
    Created: 27 Feb 2024 7:03:29pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "mixing-manager.h"

//==============================================================================
MixingManager::MixingManager(juce::AudioFormatManager& formatManagerReference, std::vector<std::unique_ptr<DeckController>>& decks)
    : formatManager(formatManagerReference)
    , decks(decks)
{
    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired(juce::RuntimePermissions::recordAudio) && !juce::RuntimePermissions::isGranted(juce::RuntimePermissions::recordAudio)) {
        juce::RuntimePermissions::request(juce::RuntimePermissions::recordAudio, [&](bool granted) { setAudioChannels(granted ? 2 : 0, 2); });
    } else {
        // Specify the number of input and output channels that we want to open
        setAudioChannels(0, 2);
    }

    // Setup audio format manager for deck wave forms.
    formatManager.registerBasicFormats();
}

MixingManager::~MixingManager()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

void MixingManager::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.
	//
	// This just lets us know the samples per block and sample rate.
	std::cout << "mixing-manager.cpp Samples per block: " << samplesPerBlockExpected << " Sample rate: " << sampleRate << std::endl;
    //
    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.
    //
    // Setup mixer to play more than one file at a time.
    // Iterate through all the decks and add them as inputs.
    for (int i = 0; i < decks.size(); i++) {
        mixerSource.addInputSource(&(*(decks[i])), false);
    }

    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MixingManager::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    mixerSource.getNextAudioBlock(bufferToFill);
}

void MixingManager::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.
    mixerSource.removeAllInputs();
    mixerSource.releaseResources();

    // Iterate through all the decks and release their resources.
    for (int i = 0; i < decks.size(); i++) {
        decks[i]->releaseResources();
    }
}
