/*
  ==============================================================================

    LogicRelay.h
    Created: 27 Feb 2024 6:46:57pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "song-model.h"
#include "logic-layer.h"

//==============================================================================
/*
*/
class PresentationInterface {
public:
    static PresentationInterface& instance()
    {
        static PresentationInterface instance;
        return instance;
    }

    void initialize(LogicLayer& logicLayer);

    std::vector<SongModel> getLibrarySongs();

    void loadSongs(std::function<void()> callback);

    void clearSongs();

    void selectDeck(int deckID);

    bool isDeckSelected(int deckID);

    void setupDeck(int deckID);

    void addSongToSelectedDeck(SongModel song);

    void removeSongFromSelectedDeck(int songIndex);

    std::vector<SongModel> getSongsFromDeck(int deckID);

    void startPlaying();

    void stopPlaying();

    void nextSong();
	
	void setPositionOfDeck(int deckID, double posInSecs);
	
	void setSpeedOfDeck(int deckID, double ratio);
	
	void setGainOfDeck(int deckID, double gain);

	juce::AudioTransportSource& getTransportSource(int deckID);
	
	juce::ResamplingAudioSource& getResampleSource(int deckID);

	SongModel* getCurrentSong(int deckID);

private:
    LogicLayer* logicLayer { nullptr };

    PresentationInterface() {};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PresentationInterface)
};
