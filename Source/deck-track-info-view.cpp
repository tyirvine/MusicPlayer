/*
  ==============================================================================

    DeckTrackInfoView.cpp
    Created: 27 Feb 2024 6:46:11pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "deck-track-info-view.h"
#include "presentation-interface.h"
#include "song-model.h"

//==============================================================================
DeckTrackInfoView::DeckTrackInfoView(int& deckID)
    : deckID(deckID)
    , songTitle("Nothing Playing")
    , leftValue(0.0f)
    , rightValue(0.0f)
{
    addAndMakeVisible(sliderUniDirectionalProgressView);
}

DeckTrackInfoView::~DeckTrackInfoView()
{
}

void DeckTrackInfoView::paint(juce::Graphics& g)
{
    // Fetch updates from the transport source.
    juce::AudioTransportSource& source = PresentationInterface::instance().getTransportSource(deckID);
    rightValue = source.getLengthInSeconds();
    leftValue = source.getCurrentPosition();

    // This is to avoid dividing by zero.
    if (rightValue != leftValue) {
        sliderUniDirectionalProgressView.setSliderValue((leftValue / rightValue) * 10.0f);
    }

    // Then grab the current song title.
    SongModel* song = PresentationInterface::instance().getCurrentSong(deckID);

    if (song != nullptr) {
        songTitle = song->getTitle();
    } else {
        songTitle = "Nothing Playing";
    }

    // Draw the top and bottom divider.
    g.setColour(STYLE_COLOR_DIVIDER_PRIMARY);
    g.drawLine(0, 0, getWidth(), 0, 1.0f);
    g.drawLine(0, getHeight(), getWidth(), getHeight(), 2.0f);

    // Draw the song title.
    g.setColour(STYLE_COLOR_DECK_FACE_PRIMARY);

    if (songTitle == "Nothing Playing") {
        g.setOpacity(0.3);
    }

    g.setFont(CustomFonts::fontSFProRegular(15));
    g.drawText(songTitle, STYLE_DECK_PADDING_PRIMARY + 4, 0, getWidth(), getHeight() - 32, juce::Justification::left);
}

void DeckTrackInfoView::resized()
{
    // Draw the track time view.
    int padding = STYLE_DECK_PADDING_PRIMARY;
    int sliderX = 0 + padding;
    int sliderY = (getHeight()) / 2;
    int sliderWidth = getWidth() - (padding * 2);
    int sliderHeight = 25;

    sliderUniDirectionalProgressView.setBounds(sliderX, sliderY, sliderWidth, sliderHeight);
}

void DeckTrackInfoView::update()
{
}
