/*
  ==============================================================================

    DeckGUI.h
    Created: 25 Jan 2024 1:41:38pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "song-manager.h"
#include "tables-queue-view.h"
#include "deck-top-bar-view.h"
#include "deck-track-control-view.h"
#include "deck-track-info-view.h"
#include "deck-playback-view.h"
#include "styles.h"

//==============================================================================
/*
*/
class DeckView : public juce::Component {
public:
    DeckView();

    ~DeckView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void mouseDown(const juce::MouseEvent& event) override;

    int getDeckID();

    void update();

    void selectDeck();

    void getQueueSongs();

private:
    void setupDeck();

    bool isSelected();

    int deckID { abs(juce::Random::getSystemRandom().nextInt()) };

    bool selected { false };

    std::vector<SongModel> queue {};

    DeckTopBarView deckTopBarView { selected };

    DeckTrackControlView deckTrackControlView { deckID };

    DeckTrackInfoView deckTrackInfoView { deckID };

    DeckPlaybackView deckPlaybackView {};

    TablesQueueView songQueueView { queue };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckView)
};
