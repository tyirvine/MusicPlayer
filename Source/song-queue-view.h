/*
  ==============================================================================

    SongQueueView.h
    Created: 7 Mar 2024 10:27:52pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "song-model.h"
#include "styles.h"

//==============================================================================
/// Must sit within a juce::Viewport component to become scrollable.
class SongQueueView : public juce::Component, public juce::TableListBoxModel {
public:
    SongQueueView(std::vector<SongModel>& songs, juce::Colour queueItemText, juce::Colour queueItemBackingPrimary, juce::Colour queueItemBackingSecondary, juce::Colour queueItemBackingSelected, juce::Colour queueDividerBar, std::string actionColumnLabel, std::string actionColumnIcon, juce::LookAndFeel_V4* lookAndFeel, std::function<void(int rowNumber)> action);

    ~SongQueueView() override;

    void resized() override;

    int getNumRows() override;

    void paintRowBackground(juce::Graphics&, int rowNumber, int width, int height, bool rowIsSelected) override;

    void paintCell(juce::Graphics&, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;

    void paint(juce::Graphics&) override;

    juce::Component* refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, juce::Component* existingComponentToUpdate) override;

    void update();

private:
    std::vector<SongModel>& songs;

    juce::Colour queueItemText;

    juce::Colour queueItemBackingPrimary;

    juce::Colour queueItemBackingSecondary;

    juce::Colour queueItemBackingSelected;

    juce::Colour queueDividerBar;

    std::string actionColumnLabel;

    std::string actionColumnIcon;
	
	std::function<void(int rowNumber)> action;

    juce::TableListBox table;

    juce::LookAndFeel_V4* lookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SongQueueView)
};
