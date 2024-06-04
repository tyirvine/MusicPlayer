/*
  ==============================================================================

	LogicRelay.cpp
	Created: 27 Feb 2024 6:46:57pm
	Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "presentation-interface.h"
#include "main-layer.h"

//==============================================================================
void PresentationInterface::initialize(LogicLayer& logicLayerReference)
{
    logicLayer = &logicLayerReference;
}

std::vector<SongModel> PresentationInterface::getLibrarySongs()
{
    return logicLayer->getLibrarySongs();
}

void PresentationInterface::loadSongs(std::function<void()> callback)
{
    logicLayer->loadSongs(callback);
}

void PresentationInterface::clearSongs()
{
    logicLayer->clearSongs();
}

void PresentationInterface::selectDeck(int deckID)
{
    logicLayer->selectDeck(deckID);
}

bool PresentationInterface::isDeckSelected(int deckID)
{
    return logicLayer->isDeckSelected(deckID);
}

void PresentationInterface::setupDeck(int deckID)
{
    logicLayer->setupDeck(deckID);
}

void PresentationInterface::addSongToSelectedDeck(SongModel song)
{
    logicLayer->addSongToSelectedDeck(song);
}

void PresentationInterface::removeSongFromSelectedDeck(int songIndex)
{
    logicLayer->removeSongFromSelectedDeck(songIndex);
}

std::vector<SongModel> PresentationInterface::getSongsFromDeck(int deckID)
{
    return logicLayer->getSongsFromDeck(deckID);
}

void PresentationInterface::startPlaying()
{
    logicLayer->startPlaying();
}

void PresentationInterface::stopPlaying()
{
    logicLayer->stopPlaying();
}

void PresentationInterface::nextSong()
{
    logicLayer->nextSong();
}

void PresentationInterface::setPositionOfDeck(int deckID, double posInSecs)
{
    logicLayer->setPositionOfDeck(deckID, posInSecs);
}

void PresentationInterface::setSpeedOfDeck(int deckID, double ratio)
{
    logicLayer->setSpeedOfDeck(deckID, ratio);
}

void PresentationInterface::setGainOfDeck(int deckID, double gain)
{
    logicLayer->setGainOfDeck(deckID, gain);
}

juce::AudioTransportSource& PresentationInterface::getTransportSource(int deckID)
{
    return logicLayer->getTransportSource(deckID);
}

juce::ResamplingAudioSource& PresentationInterface::getResampleSource(int deckID)
{
    return logicLayer->getResampleSource(deckID);
}

SongModel* PresentationInterface::getCurrentSong(int deckID)
{
    return logicLayer->getCurrentSong(deckID);
}
