/*
  ==============================================================================

	SongQueueView.cpp
	Created: 7 Mar 2024 10:27:52pm
	Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "song-queue-view.h"
#include "styles.h"
#include "button-flat-view.h"

//==============================================================================
SongQueueView::SongQueueView(std::vector<SongModel>& incomingSongs, juce::Colour queueItemText, juce::Colour queueItemBackingPrimary, juce::Colour queueItemBackingSecondary, juce::Colour queueItemBackingSelected, juce::Colour queueDividerBar, std::string actionColumnLabel, std::string actionColumnIcon, juce::LookAndFeel_V4* lookAndFeel, std::function<void(int rowNumber)> action)

    : songs(incomingSongs)
    , queueItemText(queueItemText)
    , queueItemBackingPrimary(queueItemBackingPrimary)
    , queueItemBackingSecondary(queueItemBackingSecondary)
    , queueItemBackingSelected(queueItemBackingSelected)
    , queueDividerBar(queueDividerBar)
    , actionColumnLabel(actionColumnLabel)
    , actionColumnIcon(actionColumnIcon)
    , action(action)
    , lookAndFeel(lookAndFeel)
{
    // Setup the table.
    table.getHeader().addColumn("Song", 1, (getWidth() / 7) * 5 + 1);
    table.getHeader().addColumn("Time", 2, (getWidth() / 7) * 1 + 1);
    table.getHeader().addColumn(actionColumnLabel, 3, (getWidth() / 7) * 1 + 1);

    // Setup the styling of the table.
    table.setRowHeight(STYLE_SIZE_LIBRARY_ITEM_HEIGHT);
    table.setLookAndFeel(lookAndFeel);
    table.getViewport()->setScrollBarsShown(true, false);
    table.getViewport()->getVerticalScrollBar().setColour(juce::ScrollBar::ColourIds::thumbColourId, queueDividerBar);
    table.getViewport()->getVerticalScrollBar().setColour(juce::ScrollBar::ColourIds::trackColourId, queueDividerBar);
    table.getLookAndFeel().setColour(juce::TableListBox::ColourIds::backgroundColourId, juce::Colours::transparentBlack);

    // Setup the data for the table.
    table.setModel(this);

    // Make the table visible.
    addAndMakeVisible(table);
}

SongQueueView::~SongQueueView()
{
}

void SongQueueView::resized()
{
    table.getHeader().setColumnWidth(1, (getWidth() / 7) * 5);
    table.getHeader().setColumnWidth(2, (getWidth() / 7) * 1);
    table.getHeader().setColumnWidth(3, (getWidth() / 7) * 1);
    table.setBounds(0, 0, getWidth(), getHeight());
}

int SongQueueView::getNumRows()
{
    return (int)songs.size();
}

void SongQueueView::paint(juce::Graphics& g)
{
    // Draw the rows if there are songs and based on the height.
    if (songs.size() > 0 && getHeight() > (songs.size() * STYLE_SIZE_LIBRARY_ITEM_HEIGHT)) {
        // Calculate the number of rows needed.
        int rowCount = getHeight() / STYLE_SIZE_LIBRARY_ITEM_HEIGHT;

        // Draw rows in the background.
        for (int i = 0; i < rowCount; i++) {
            int y = 28 + i * STYLE_SIZE_LIBRARY_ITEM_HEIGHT;
            juce::Colour color = (i % 2 == 0) ? queueItemBackingPrimary : queueItemBackingSecondary;
            g.setColour(color);
            g.fillRect(0, y, getWidth(), STYLE_SIZE_LIBRARY_ITEM_HEIGHT);
        }
    } else {
        g.fillAll(queueItemBackingSecondary);
    }
}

void SongQueueView::paintRowBackground(juce::Graphics& g, int rowNumber, int width, int height, bool rowIsSelected)
{
    // Sets the background color for the selected row.
    if (rowIsSelected) {
        g.fillAll(queueItemBackingSelected);
    }
    // Sets the paint color for all unselected rows based on row number in order to alternate.
    // This is done for better visibility.
    else if (rowNumber % 2 == 0) {
        juce::Colour color = queueItemBackingPrimary;
        g.fillAll(color);
    } else {
        juce::Colour color = queueItemBackingSecondary;
        g.fillAll(color);
    }
}

void SongQueueView::paintCell(juce::Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
    // Setup the cell styling.
    g.setColour(queueItemText);
    g.setFont(CustomFonts::fontSFProRegular(15));

    // Setup the text container.
    std::string text = "";

    // Draw the song title.
    if (columnId == 1) {
        text = songs[rowNumber].getTitle();
    }
    // Draw the song duration.
    else if (columnId == 2) {
        text = songs[rowNumber].getDuration();
    }

    // Draw the text.
    g.drawText(text, STYLE_SIZE_LIBRARY_MARGIN, 0, width - 4, height, juce::Justification::centredLeft, true);
}

void SongQueueView::update()
{
    table.updateContent();
    table.repaint();
}

juce::Component* SongQueueView::refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, juce::Component* existingComponentToUpdate)
{
    // Creates a component at the column.
    if (columnId == 3 && existingComponentToUpdate == nullptr) {
        // Creates an add to queue button for each track and passes the row number to the component.
        juce::Colour backingColor = juce::Colours::transparentBlack;
        juce::Colour faceColor = queueItemText;
        std::string label = actionColumnIcon;

        // Setup the callback.
        std::function<void()> callback = [=]() {
            action(rowNumber);
        };

        // Create the button.
        ButtonFlatView* addToQueueButton = new ButtonFlatView(label, callback, backingColor, faceColor);
        juce::String id { std::to_string(rowNumber) };

        // Setup the button.
        addToQueueButton->setComponentID(id);
        existingComponentToUpdate = addToQueueButton;
    }
    return existingComponentToUpdate;
}
