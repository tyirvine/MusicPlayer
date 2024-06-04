/*
  ==============================================================================

    TablesView.h
    Created: 27 Feb 2024 6:44:54pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "table-view.h"
#include "button-flat-view.h"
#include "styles.h"

//==============================================================================
/*
*/
class TablesView : public juce::Component {
public:
    TablesView(std::function<void()> toggleLibraryAction);

    ~TablesView() override;

    void paint(juce::Graphics&) override;
	
	void paintOverChildren(juce::Graphics&) override;

    void resized() override;

private:
    TableView leftTableView { "Left Table" };

    TableView rightTableView { "Right Table" };

	std::function<void()> toggleLibraryAction;
	
    ButtonFlatView toggleSongLibraryVisibility { "􀏚", toggleLibraryAction };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TablesView)
};
