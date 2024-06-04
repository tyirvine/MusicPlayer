/*
  ==============================================================================

	LogicLayer.cpp
	Created: 27 Feb 2024 7:04:24pm
	Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "logic-layer.h"

//==============================================================================
LogicLayer::LogicLayer()
{
}

LogicLayer::~LogicLayer()
{
}

std::vector<SongModel> LogicLayer::getLibrarySongs()
{
    std::cout << "logic-layer.cpp getSongs()" << std::endl;
    return songManager.getSongs();
}

void LogicLayer::loadSongs(std::function<void()> callback)
{
    std::cout << "logic-layer.cpp loadSongs()" << std::endl;
    songManager.loadSongs(callback);
}

void LogicLayer::clearSongs()
{
    std::cout << "logic-layer.cpp clearSongs()" << std::endl;
    songManager.clearSongs();
}

void LogicLayer::selectDeck(int deckID)
{
    deckManager.selectDeck(deckID);
}

bool LogicLayer::isDeckSelected(int deckID)
{
    return deckManager.isDeckSelected(deckID);
}

void LogicLayer::setupDeck(int deckID)
{
    deckManager.setupDeck(deckID);
}

void LogicLayer::addSongToSelectedDeck(SongModel song)
{
    deckManager.addSongToSelectedDeck(song);
}

void LogicLayer::removeSongFromSelectedDeck(int songIndex)
{
    deckManager.removeSongFromSelectedDeck(songIndex);
}

std::vector<SongModel> LogicLayer::getSongsFromDeck(int deckID)
{
    return deckManager.getSongsFromDeck(deckID);
}

void LogicLayer::startPlaying()
{
    deckManager.startPlaying();
}

void LogicLayer::stopPlaying()
{
    deckManager.stopPlaying();
}

void LogicLayer::nextSong()
{
    deckManager.nextSong();
}

void LogicLayer::setPositionOfDeck(int deckID, double posInSecs)
{
    deckManager.setPositionOfDeck(deckID, posInSecs);
}

void LogicLayer::setSpeedOfDeck(int deckID, double ratio)
{
    deckManager.setSpeedOfDeck(deckID, ratio);
}

void LogicLayer::setGainOfDeck(int deckID, double gain)
{
    deckManager.setGainOfDeck(deckID, gain);
}

juce::AudioTransportSource& LogicLayer::getTransportSource(int deckID)
{
    return deckManager.getTransportSource(deckID);
}

juce::ResamplingAudioSource& LogicLayer::getResampleSource(int deckID)
{
    return deckManager.getResampleSource(deckID);
}

SongModel* LogicLayer::getCurrentSong(int deckID)
{
    return deckManager.getCurrentSong(deckID);
}
