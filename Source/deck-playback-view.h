/*
  ==============================================================================

    DeckPlaybackView.h
    Created: 27 Feb 2024 6:46:26pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "button-flat-view.h"
#include "styles.h"

//==============================================================================
/*
*/
class DeckPlaybackView : public juce::Component {
public:
    DeckPlaybackView();

    ~DeckPlaybackView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void update();

    void playPause();

    void nextSong();

private:
    bool playing { false };

	ButtonFlatView playPauseButton { "􀊄", [=]() { playPause(); }, STYLE_COLOR_BACKING_PRIMARY, STYLE_COLOR_DECK_FACE_PRIMARY };

	ButtonFlatView nextButton { "􀊐", [=]() { nextSong(); }, STYLE_COLOR_BACKING_PRIMARY, STYLE_COLOR_DECK_FACE_PRIMARY };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckPlaybackView)
};
