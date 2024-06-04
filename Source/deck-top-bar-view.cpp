/*
  ==============================================================================

    DeckTopBarView.cpp
    Created: 27 Feb 2024 6:45:27pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "deck-top-bar-view.h"

//==============================================================================
DeckTopBarView::DeckTopBarView(bool& deckSelected)
    : deckSelected(deckSelected)
{
}

DeckTopBarView::~DeckTopBarView()
{
}

void DeckTopBarView::paint(juce::Graphics& g)
{
    // Paint a little red dot if the deck is selected.
    if (deckSelected) {
        g.setColour(STYLE_COLOR_SLIDER_BI_PRIMARY);
        g.fillEllipse(getWidth(), getHeight() / 2, 10.0f, 10.0f);
    }
}

void DeckTopBarView::resized()
{
}

void DeckTopBarView::update()
{
    repaint();
}
