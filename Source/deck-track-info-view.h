/*
  ==============================================================================

    DeckTrackInfoView.h
    Created: 27 Feb 2024 6:46:11pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "styles.h"
#include "slider-uni-directional-progress-view.h"
#include "presentation-interface.h"

//==============================================================================
/*
*/
class DeckTrackInfoView : public juce::Component {
public:
    DeckTrackInfoView(int& deckID);

    ~DeckTrackInfoView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void update();

private:
    int& deckID;

    std::string songTitle;

    float leftValue;

    float rightValue;

    std::function<void(float)> action = [=](float value) {
        juce::AudioTransportSource& source = PresentationInterface::instance().getTransportSource(deckID);
        float position = source.getLengthInSeconds() * value;
        PresentationInterface::instance().setPositionOfDeck(deckID, position);
    };

    SliderUniDirectionalProgressView sliderUniDirectionalProgressView { leftValue, rightValue, action };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckTrackInfoView)
};
