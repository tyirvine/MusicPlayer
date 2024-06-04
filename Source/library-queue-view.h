/*
  ==============================================================================

    LibraryQueueView.h
    Created: 10 Mar 2024 11:53:59am
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "song-model.h"
#include "song-queue-view.h"
#include "presentation-interface.h"
#include "styles.h"

//==============================================================================
/*
*/
class LibraryQueueView : public juce::Component {
public:
    LibraryQueueView(std::vector<SongModel>& songs);

    ~LibraryQueueView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void update();

private:
    std::vector<SongModel>& songs;

    LibraryTableLookAndFeel lookAndFeel;

    std::function<void(int)> action { [=](int rowNumber) {
        SongModel song = songs[rowNumber];
        PresentationInterface::instance().addSongToSelectedDeck(song);
    } };

    SongQueueView songQueueView { songs, STYLE_COLOR_LIBRARY_TEXT_ITEM, STYLE_COLOR_LIBRARY_BACKING_ITEM_PRIMARY, STYLE_COLOR_LIBRARY_BACKING_ITEM_SECONDARY, STYLE_COLOR_RAISED_FACE, STYLE_COLOR_LIBRARY_DIVIDER_BAR, "Queue", juce::String(juce::CharPointer_UTF8("\xf4\x80\x85\xbc")).toStdString(), &lookAndFeel, action };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LibraryQueueView)
};
