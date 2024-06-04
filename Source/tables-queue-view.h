/*
  ==============================================================================

    TablesQueueView.h
    Created: 10 Mar 2024 11:54:10am
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "song-model.h"
#include "song-queue-view.h"
#include "presentation-interface.h"

//==============================================================================
/*
*/
class TablesQueueView : public juce::Component {
public:
    TablesQueueView(std::vector<SongModel>& songs);

    ~TablesQueueView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void update();

private:
    std::vector<SongModel>& songs;

    DecksTableLookAndFeel lookAndFeel;

    std::function<void(int)> action { [=](int rowNumber) {
        PresentationInterface::instance().removeSongFromSelectedDeck(rowNumber);
    } };

    SongQueueView songQueueView { songs, STYLE_COLOR_LIBRARY_TEXT_ITEM, STYLE_COLOR_BACKING_TERTIARY, STYLE_COLOR_BACKING_PRIMARY, STYLE_COLOR_TABLES_DIVIDER, STYLE_COLOR_DIVIDER_PRIMARY, "Remove", juce::String(juce::CharPointer_UTF8("\xf4\x80\xb1\x8d")).toStdString(), &lookAndFeel, action };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TablesQueueView)
};
