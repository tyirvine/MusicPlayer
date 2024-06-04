/*
  ==============================================================================

    TableView.cpp
    Created: 27 Feb 2024 6:45:10pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "table-view.h"

//==============================================================================
TableView::TableView(std::string side)
{
    bottomBarView.update(side);
    addAndMakeVisible(deckView);
    addAndMakeVisible(bottomBarView);
}

TableView::~TableView()
{
}

void TableView::paint(juce::Graphics& g)
{
    // Draw the top divider.
    g.setColour(STYLE_COLOR_DIVIDER_PRIMARY);
    g.drawLine(0, STYLE_SIZE_FLAT_BUTTON, getWidth(), STYLE_SIZE_FLAT_BUTTON, 1.0f);
}

void TableView::resized()
{
    // Setup the bottom bar.
    int bottomBarHeight = STYLE_SIZE_BAR_HEIGHT;
    bottomBarView.setBounds(0, getHeight() - bottomBarHeight, getWidth(), bottomBarHeight);

    // Set the deck view bounds accounting for the bottom bar.
    deckView.setBounds(0, 0, getWidth(), getHeight() - bottomBarHeight);
}
