/*
  ==============================================================================

    TablesView.cpp
    Created: 27 Feb 2024 6:44:54pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "tables-view.h"

//==============================================================================
TablesView::TablesView(std::function<void()> toggleLibraryAction)
    : toggleLibraryAction(toggleLibraryAction)
{
    addAndMakeVisible(leftTableView);
    addAndMakeVisible(rightTableView);
    addAndMakeVisible(toggleSongLibraryVisibility);
}

TablesView::~TablesView()
{
}

void TablesView::paint(juce::Graphics& g)
{
}

void TablesView::paintOverChildren(juce::Graphics& g)
{
    g.setColour(STYLE_COLOR_TABLES_DIVIDER);
    g.drawLine(getWidth() / 2, 0, getWidth() / 2, getHeight(), 1.0f);
}

void TablesView::resized()
{
    // Setup the buttons.
    int buttonSize = STYLE_SIZE_FLAT_BUTTON;
    toggleSongLibraryVisibility.setBounds(0, 0, buttonSize, buttonSize);

    // Setup the tables.
    leftTableView.setBounds(0, 0, getWidth() / 2, getHeight());
    rightTableView.setBounds(getWidth() / 2, 0, getWidth() / 2, getHeight());
}
