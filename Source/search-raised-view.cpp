/*
  ==============================================================================

	SearchRaisedView.cpp
	Created: 27 Feb 2024 6:38:34pm
	Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "search-raised-view.h"
#include "styles.h"

//==============================================================================
SearchRaisedView::SearchRaisedView(std::function<void()> listener)
{
	// Sets up the text editor listener.
	textEditor.onTextChange = listener;
	
	// Style the editor.
	textEditor.setLookAndFeel(&lookAndFeel);
	textEditor.setJustification(juce::Justification::verticallyCentred);
	textEditor.setFont(CustomFonts::fontSFProMedium(15));
	textEditor.setMultiLine(false);

	// Display the text editor.
	addAndMakeVisible(textEditor);
}

SearchRaisedView::~SearchRaisedView()
{
}

void SearchRaisedView::paint(juce::Graphics& g)
{
	int x = 0;
	int y = 0;
	int width = getWidth();
	int height = getHeight();

	// Draw the text editor's outline.
	g.setColour(STYLE_COLOR_RAISED_BORDER);
	g.fillRoundedRectangle(x, y, width, height, 6.0f);
	
	// Draw the text editor's background.
	g.setColour(STYLE_COLOR_RAISED_FACE);
	g.fillRoundedRectangle(x + 1, y + 1, width - 2, height - 2, 5.5f);
	
	// Draw the magnifine glass.
	g.setColour(STYLE_COLOR_RAISED_PLACEHOLDER);
	g.setFont(CustomFonts::fontSFProMedium(15));
	g.drawText(juce::CharPointer_UTF8 ("\xf4\x80\x8a\xab"), x + 8, y + 1, width, height, juce::Justification::left);
}

void SearchRaisedView::resized()
{
	textEditor.setBounds(24, 3, getWidth() - 36, getHeight() - 8);
}

std::string SearchRaisedView::getText() {
	return textEditor.getText().toStdString();
}
