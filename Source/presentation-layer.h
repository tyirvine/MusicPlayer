/*
  ==============================================================================

    PresentationLayer.h
    Created: 27 Feb 2024 6:47:14pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "interface-debug-view.h"
#include "song-library-view.h"
#include "presentation-interface.h"
#include "tables-view.h"

//==============================================================================
/*
*/
class PresentationLayer : public juce::Component {
public:
    PresentationLayer();

    ~PresentationLayer() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void toggleLibraryView();

private:
    //#if DEBUG
    //    // This view is used for debugging and testing interface views.
    //    InterfaceDebugView interfaceDebugView {};
    //
    //    // This shows and hides the interface debug view.
    //    juce::TextButton toggleInterfaceDebugView { "Toggle Interface Debug View" };
    //#endif

    bool libraryVisible { false };

    SongLibraryView songLibraryView {};

    TablesView tablesView { [=]() { toggleLibraryView(); } };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PresentationLayer)
};
