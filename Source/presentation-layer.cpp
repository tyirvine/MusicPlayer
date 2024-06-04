/*
  ==============================================================================

    PresentationLayer.cpp
    Created: 27 Feb 2024 6:47:14pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "presentation-layer.h"

//==============================================================================
PresentationLayer::PresentationLayer()
{
    // Reference available in the report. [7]
    // https://forum.juce.com/t/unfocus-texteditor-when-user-clicks-off/16920
    // We need to allow the presentation layer to accept focus.
    this->setWantsKeyboardFocus(true);

    // Setup the song library view.
    addAndMakeVisible(songLibraryView);

    // Setup the tables view.
    addAndMakeVisible(tablesView);

    //#if DEBUG
    //	// Set the opacity of the button.
    //	toggleInterfaceDebugView.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::transparentBlack);
    //
    //	// We only want this view to be visible when debugging.
    //	addAndMakeVisible(interfaceDebugView);
    //	addAndMakeVisible(toggleInterfaceDebugView);
    //
    //	// Setup the interface toggle.
    //	bool toggleInterfaceDebugViewButtonState = false;
    //	// Reference available in report. [2]
    //	// https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170
    //	// Make the interface debug view hidden by default.
    //	interfaceDebugView.setVisible(false);
    //	toggleInterfaceDebugView.onClick = [=]() mutable {
    //		interfaceDebugView.setVisible(toggleInterfaceDebugViewButtonState);
    //		toggleInterfaceDebugViewButtonState = !toggleInterfaceDebugViewButtonState;
    //	};
    //#endif
}

PresentationLayer::~PresentationLayer()
{
}

void PresentationLayer::paint(juce::Graphics& g)
{
    // Add in universal styling.
    g.fillAll(juce::Colour(0, 0, 0));
    g.setFont(16.0f);
}

void PresentationLayer::resized()
{
    // Setup presentation view size logic.
    // Set the library view bounds.
    int songLibraryWidth;
    if (libraryVisible == false) {
        songLibraryWidth = 475;
        songLibraryView.setBounds(0, 0, songLibraryWidth, getHeight());
    } else {
        songLibraryWidth = 0;
    }

    // Set the tables view bounds.
    tablesView.setBounds(songLibraryWidth, 0, getWidth() - songLibraryWidth, getHeight());

    //#if DEBUG
    //	// Passes down the window size to the interface debug view.
    //	interfaceDebugView.setBounds(getLocalBounds());
    //	toggleInterfaceDebugView.setBounds(10, getHeight() - 40, 200, 30);
    //#endif
}

void PresentationLayer::toggleLibraryView()
{
    songLibraryView.setVisible(libraryVisible);
    libraryVisible = !libraryVisible;
    resized();
}
