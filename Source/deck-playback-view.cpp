/*
  ==============================================================================

    DeckPlaybackView.cpp
    Created: 27 Feb 2024 6:46:26pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "deck-playback-view.h"
#include "presentation-interface.h"

//==============================================================================
DeckPlaybackView::DeckPlaybackView()
{
    addAndMakeVisible(playPauseButton);
    addAndMakeVisible(nextButton);
}

DeckPlaybackView::~DeckPlaybackView()
{
}

void DeckPlaybackView::paint(juce::Graphics& g)
{
}

void DeckPlaybackView::resized()
{
    int buttonSize = 34;
    int buttonSizeHalf = buttonSize / 2;

    int centrePointX = getWidth() / 2;
    int centrePointY = (getHeight() / 2) - buttonSizeHalf;

    playPauseButton.setBounds(centrePointX - buttonSizeHalf, centrePointY, buttonSize, buttonSize);
    nextButton.setBounds(centrePointX + buttonSize - buttonSizeHalf, centrePointY, buttonSize, buttonSize);
}

void DeckPlaybackView::update()
{
}

void DeckPlaybackView::playPause()
{
    if (playing) {
        PresentationInterface::instance().stopPlaying();
        playPauseButton.setButtonText("􀊄");
    } else {
        PresentationInterface::instance().startPlaying();
        playPauseButton.setButtonText("􀊆");
    }

    playing = !playing;
}

void DeckPlaybackView::nextSong()
{
    PresentationInterface::instance().nextSong();
}
