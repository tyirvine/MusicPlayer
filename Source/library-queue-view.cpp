/*
  ==============================================================================

    LibraryQueueView.cpp
    Created: 10 Mar 2024 11:53:59am
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "library-queue-view.h"

//==============================================================================
LibraryQueueView::LibraryQueueView(std::vector<SongModel>& songs)
    : songs(songs)
{
	addAndMakeVisible(songQueueView);
}

LibraryQueueView::~LibraryQueueView()
{
}

void LibraryQueueView::paint(juce::Graphics& g)
{
}

void LibraryQueueView::resized()
{
    songQueueView.setBounds(0, 0, getWidth(), getHeight());
}

void LibraryQueueView::update()
{
    songQueueView.update();
}
