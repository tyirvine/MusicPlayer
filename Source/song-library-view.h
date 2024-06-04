/*
  ==============================================================================

    PlaylistComponent.h
    Created: 8 Feb 2024 11:37:38am
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <vector>
#include <string>
#include "search-raised-view.h"
#include "button-raised-view.h"
#include "bottom-bar-view.h"
#include "styles.h"
#include "song-model.h"
#include "library-queue-view.h"
#include "presentation-interface.h"

//==============================================================================
/*
*/
class SongLibraryView : public juce::Component {
public:
    SongLibraryView();

    ~SongLibraryView() override;

    void paint(juce::Graphics&) override;
	
	void paintOverChildren(juce::Graphics&) override;
	
    void resized() override;

private:
    // MARK: Calls.

    void update(bool refreshSongs = true);

    std::vector<SongModel> getSongs();

    void loadSongs();

    void clearSongs();

    // MARK: Interface logic.

    std::vector<SongModel> songs {};

    void search();

    // MARK: Interface views.

	SearchRaisedView searchView { [=] { search(); } };

    ButtonRaisedView loadButtonView { "Load", "􀑬", [=] { loadSongs(); } };

    ButtonRaisedView ejectButtonView { "Eject", "􁏏", [=] { clearSongs(); } };

    LibraryQueueView songQueueView { songs };

    BottomBarView bottomBarView { "", STYLE_COLOR_LIBRARY_BACKING_BAR, STYLE_COLOR_LIBRARY_DIVIDER_BAR, STYLE_COLOR_LIBRARY_TEXT_BAR };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SongLibraryView)
};
