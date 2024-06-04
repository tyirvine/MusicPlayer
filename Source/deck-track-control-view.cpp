/*
  ==============================================================================

    DeckTrackControlView.cpp
    Created: 27 Feb 2024 6:45:42pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "deck-track-control-view.h"

//==============================================================================
DeckTrackControlView::DeckTrackControlView(int& deckID)
    : deckID(deckID)
{
    addAndMakeVisible(sliderSpeed);
    addAndMakeVisible(sliderVolume);
    //    addAndMakeVisible(sliderVerticalHigh);
    //    addAndMakeVisible(sliderVerticalMid);
    //    addAndMakeVisible(sliderVerticalLow);
    //    addAndMakeVisible(audioLevelView);
}

DeckTrackControlView::~DeckTrackControlView()
{
}

void DeckTrackControlView::paint(juce::Graphics& g)
{
    setupColumns();

    // Fetch data.
    juce::AudioTransportSource& transportSource = PresentationInterface::instance().getTransportSource(deckID);
    juce::ResamplingAudioSource& resamplingSource = PresentationInterface::instance().getResampleSource(deckID);

    // Assign volume.
    sliderVolume.setSliderValue(transportSource.getGain() * 10.0f);
    sliderSpeed.setSliderValue(resamplingSource.getResamplingRatio() * 5.0f);

    // Draw dividers.
    g.setColour(STYLE_COLOR_DIVIDER_PRIMARY);

    // Paint the top and bottom divider.
    g.drawLine(0, 0, getWidth(), 0, 1.0f);
    g.drawLine(0, getHeight(), getWidth(), getHeight(), 2.0f);

    // Paint the vertical dividers.
    //    int xLeftDivider = middleColumnX;
    //    int xRightDivider = rightColumnX;
    //    g.drawLine(xLeftDivider, 0, xLeftDivider, getHeight(), 1.0f);
    //    g.drawLine(xRightDivider, 0, xRightDivider, getHeight(), 1.0f);
}

void DeckTrackControlView::resized()
{
    setupColumns();

    // Properties for all of the sliders.
    int padding = STYLE_DECK_PADDING_PRIMARY;

    // Setup the left sliders.
    int xLeftSlider = leftColumnX + padding;
    int yLeftSlider = 0 + padding;
    int widthLeftSlider = getWidth() - (padding * 2);
    int heightLeftSlider = (getHeight() - (padding * 3)) / 2;

    sliderSpeed.setBounds(xLeftSlider, yLeftSlider, widthLeftSlider, heightLeftSlider);
    sliderVolume.setBounds(xLeftSlider, yLeftSlider + heightLeftSlider + padding, widthLeftSlider, heightLeftSlider);

    // Setup the middle sliders.
    int middlePadding = 12;
    int xMiddleSlider = middleColumnX + padding;
    int yMiddleSlider = 0 + padding;
    int widthMiddleSlider = (middleColumnWidth - (padding * 2) - (middlePadding * 2)) / 3;
    int heightMiddleSlider = (getHeight() - (padding * 2));

    sliderVerticalHigh.setBounds(xMiddleSlider, yMiddleSlider, widthMiddleSlider, heightMiddleSlider);
    sliderVerticalMid.setBounds(xMiddleSlider + widthMiddleSlider + middlePadding, yMiddleSlider, widthMiddleSlider, heightMiddleSlider);
    sliderVerticalLow.setBounds(xMiddleSlider + widthMiddleSlider + middlePadding + widthMiddleSlider + middlePadding, yMiddleSlider, widthMiddleSlider, heightMiddleSlider);

    // Setup the right audio levels.
    int xRightLevels = rightColumnX + padding;
    int yRightLevels = 0 + padding;
    int widthRightLevels = (rightColumnWidth - (padding * 2));
    int heightRightLevels = (getHeight() - (padding * 2));

    audioLevelView.setBounds(xRightLevels, yRightLevels, widthRightLevels, heightRightLevels);
}

void DeckTrackControlView::update()
{
}

void DeckTrackControlView::setupColumns()
{
    rightColumnWidth = 70;
    rightColumnX = getWidth() - rightColumnWidth;

    middleColumnWidth = 160;
    middleColumnX = getWidth() - middleColumnWidth - rightColumnWidth;

    leftColumnWidth = getWidth() - middleColumnWidth - rightColumnWidth;
    leftColumnX = 0;
}
