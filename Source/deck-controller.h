/*
  ==============================================================================

    DeckManager.h
    Created: 27 Feb 2024 7:03:42pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "song-model.h"

//==============================================================================
/*
*/
class DeckController : public juce::AudioSource, public juce::ChangeListener {
public:
    DeckController(int deckID, juce::AudioFormatManager& formatManagerReference);

    ~DeckController() override;

    enum TransportState {
        Stopped,
        Ended,
        Playing,
    };

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;

    void releaseResources() override;

    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

    void onChangeOfTransportState(TransportState newState);

    void loadURL(juce::URL audioURL);

    void setGain(double gain);

    void setSpeed(double ratio);

    void setPosition(double posInSecs);

    void setPositionRelative(double posInSecs);

    double getPositionRelative();

    void start(bool forcePlay = false);

    void stop();

    void end();

    void setSelected(bool selected);

    bool isSelected();

    int getDeckID();

    void addSong(SongModel song);

    void removeSong(int songIndex);

    std::vector<SongModel> getSongs();

    void nextSong();

    juce::AudioTransportSource& getTransportSource();
	
	juce::ResamplingAudioSource& getResampleSource();

    SongModel* getCurrentSong();

private:
    int deckID;

    bool deckSelected { false };

    TransportState transportState;

    std::vector<SongModel> songs {};

    SongModel* currentSong;

    juce::AudioFormatManager& formatManager;

    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;

    juce::AudioTransportSource transportSource;

    juce::ResamplingAudioSource resampleSource { &transportSource, false, 2 };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckController);
};
