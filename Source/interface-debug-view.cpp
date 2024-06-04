/*
  ==============================================================================

    InterfaceDebugView.cpp
    Created: 27 Feb 2024 8:49:04pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "interface-debug-view.h"

//==============================================================================
InterfaceDebugView::InterfaceDebugView()
{
    // We need to allow this layer to accept focus so that it pulls it away from the search field.
    this->setWantsKeyboardFocus(true);

    // Make visible all the views for testing.
    addAndMakeVisible(buttonRaisedView);
    addAndMakeVisible(buttonFlatView);
    addAndMakeVisible(sliderUniDirectionalView);
    addAndMakeVisible(sliderUniDirectionalProgressView);
    addAndMakeVisible(sliderBiDirectionalView);
    addAndMakeVisible(sliderBiDirectionalVerticalView);
    addAndMakeVisible(searchRaisedView);
    addAndMakeVisible(bottomBarView);
    addAndMakeVisible(audioLevelView);
}

InterfaceDebugView::~InterfaceDebugView()
{
}

void InterfaceDebugView::paint(juce::Graphics& g)
{
    // Provides a background to display the components on.
    g.fillAll(juce::Colour(20, 20, 20));
}

void InterfaceDebugView::resized()
{
    int xSpacer = 20;
    int ySpacer = 100;

    // Sets up all our views in the debug view.
    buttonRaisedView.setBounds(xSpacer * 1, ySpacer * 2, 80, 30);
    buttonFlatView.setBounds(xSpacer * 1, ySpacer * 3, STYLE_SIZE_FLAT_BUTTON, STYLE_SIZE_FLAT_BUTTON);
    sliderUniDirectionalView.setBounds(xSpacer * 1, ySpacer * 4, 500, 46);
    sliderUniDirectionalProgressView.setBounds(xSpacer * 30, ySpacer * 4, 500, 46);
    sliderBiDirectionalView.setBounds(xSpacer * 1, ySpacer * 5, 300, 46);
    sliderBiDirectionalVerticalView.setBounds(xSpacer * 20, ySpacer * 5, 32, 106);
    searchRaisedView.setBounds(xSpacer * 1, ySpacer * 6, 282, 30);
    bottomBarView.setBounds(xSpacer * 1, ySpacer * 7, 400, STYLE_SIZE_BAR_HEIGHT);
    audioLevelView.setBounds(xSpacer * 1, ySpacer * 8, 100, 20);
}
