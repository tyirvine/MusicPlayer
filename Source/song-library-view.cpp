/*
  ==============================================================================

	PlaylistComponent.cpp
	Created: 8 Feb 2024 11:37:38am
	Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "song-library-view.h"
#include "styles.h"
#include "presentation-layer.h"

//==============================================================================
SongLibraryView::SongLibraryView()
{
    // Assign the songs.
    update();

    // Make all the views visible.
    addAndMakeVisible(searchView);
    addAndMakeVisible(loadButtonView);
    addAndMakeVisible(ejectButtonView);
    addAndMakeVisible(songQueueView);
    addAndMakeVisible(bottomBarView);
}

SongLibraryView::~SongLibraryView()
{
}

void SongLibraryView::paint(juce::Graphics& g)
{
    g.fillAll(STYLE_COLOR_BACKING_SECONDARY);
}

void SongLibraryView::paintOverChildren(juce::Graphics& g)
{
	// MARK: Draws the divider on the right side of the library view.
	g.setColour(STYLE_COLOR_DIVIDER_PRIMARY);
	g.drawLine(getWidth(), 0, getWidth(), getHeight(), 2.0f);
	
	// MARK: Writes the message over the view when no songs are present.
    // Determine what text to write.
    std::string icon;
    std::string label;

    // A message for when there are no songs.
    if (searchView.getText().empty()) {
        icon = juce::String(juce::CharPointer_UTF8("\xf4\x80\xac\x95")).toStdString();
        label = "No songs added. ";
    }
    // A message for when the user is searching.
    else {
        icon = juce::String(juce::CharPointer_UTF8("\xf4\x80\x8a\xab")).toStdString();
        label = "No songs found. ";
    }
	
    // Draw the text.
    if (songs.size() < 1) {
        g.setColour(juce::Colour(juce::uint8(255), juce::uint8(255), juce::uint8(255), 0.5f));

        // Draw the icon.
        g.setFont(CustomFonts::fontSFProBold(40));
        g.drawText(icon, 0, getHeight() / 2 - 75, getWidth(), 50, juce::Justification::centred);

        // Draw the label.
        g.setFont(CustomFonts::fontSFProMedium(22));
        g.drawMultiLineText(label, 0, getHeight() / 2, getWidth(), juce::Justification::centred);
    }
}

void SongLibraryView::resized()
{
    int topBarHeight = 58;
    int topBarSpacing = 14;
    int buttonWidth = 82;
    int searchWidth = getWidth() - (topBarSpacing * 4) - (buttonWidth * 2) - 2;
    int interactableHeight = 30;
    int bottomBarHeight = STYLE_SIZE_BAR_HEIGHT;

    // Setup the top bar interactables.
    searchView.setBounds(topBarSpacing, topBarSpacing, searchWidth, interactableHeight);
    loadButtonView.setBounds(topBarSpacing + searchWidth + topBarSpacing, topBarSpacing, buttonWidth, interactableHeight);
    ejectButtonView.setBounds(topBarSpacing + searchWidth + topBarSpacing + buttonWidth + topBarSpacing, topBarSpacing, buttonWidth, interactableHeight);

    // Sets up the table sizing.
    songQueueView.setBounds(0, topBarHeight, getWidth(), getHeight() - topBarHeight - bottomBarHeight);

    // Set up the bottom bar view.
    bottomBarView.setBounds(0, getHeight() - bottomBarHeight, getWidth(), bottomBarHeight);
}

void SongLibraryView::search()
{
    // Get the search text.
    std::string searchText = searchView.getText();

    // Escape if the there's no search text.
    if (searchText.empty()) {
        update();
        return;
    }

    // A container to hold the search songs.
    std::vector<SongModel> searchSongs {};

    // Get the library's songs.
    std::vector<SongModel> librarySongs { getSongs() };

    // Sort the songs based on the search text.
    for (int i = 0; i < librarySongs.size(); i++) {
        SongModel song = librarySongs[i];
		
		// Lowercase both the search text and the title text.
		std::string searchTextLowercased = juce::String(searchText).toLowerCase().toStdString();
		std::string titleTextLowercased = juce::String(song.getTitle()).toLowerCase().toStdString();

        // Check if the search matches the text.
        if (titleTextLowercased.find(searchTextLowercased) != std::string::npos) {
            searchSongs.push_back(song);
        }
    }

    // Reassign the songs.
    songs = searchSongs;

    // Update the interface.
    update(false);
}

void SongLibraryView::update(bool refreshSongs)
{
    // Get the songs.
    if (refreshSongs) {
        songs = getSongs();
    }

    // Then update the interface views.
    songQueueView.update();
    bottomBarView.update(std::to_string(songs.size()) + " Songs");
}

std::vector<SongModel> SongLibraryView::getSongs()
{
    return PresentationInterface::instance().getLibrarySongs();
}

void SongLibraryView::loadSongs()
{
    // This is the callback to make after the songs are loaded.
    std::function<void()> callback = [=]() {
        update();
    };

    // Load the songs.
    PresentationInterface::instance().loadSongs(callback);
}

void SongLibraryView::clearSongs()
{
    PresentationInterface::instance().clearSongs();
    update();
}
