/*
  ==============================================================================

    DeckTrackControlView.h
    Created: 27 Feb 2024 6:45:42pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "styles.h"
#include "slider-bi-directional-view.h"
#include "slider-bi-directional-vertical-view.h"
#include "slider-uni-directional-view.h"
#include "audio-level-view.h"
#include "presentation-interface.h"

//==============================================================================
/*
*/
class DeckTrackControlView : public juce::Component {
public:
    DeckTrackControlView(int& deckID);

    ~DeckTrackControlView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

    void update();

private:
	
	int& deckID;
	
	int leftColumnWidth;
	
	int leftColumnX;

	int middleColumnWidth;
	
	int middleColumnX;

	int rightColumnWidth;
	
	int rightColumnX;
	
	void setupColumns();
	
	std::function<void(float)> speedAction = [=](float value) {
		float floorValue = std::max(value, -0.99f);
		PresentationInterface::instance().setSpeedOfDeck(deckID, (floorValue + 1));
	};

    SliderBiDirectionalView sliderSpeed { "Speed", speedAction };
	
	std::function<void(float)> volumeAction = [=](float value) {
		PresentationInterface::instance().setGainOfDeck(deckID, value);
	};

    SliderUniDirectionalView sliderVolume {"Volume", volumeAction };

    SliderBiDirectionalVerticalView sliderVerticalHigh {"High", [=](float value) {}};

    SliderBiDirectionalVerticalView sliderVerticalMid {"Mid", [=](float value) {}};

    SliderBiDirectionalVerticalView sliderVerticalLow {"Low", [=](float value) {}};

    AudioLevelView audioLevelView {};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DeckTrackControlView)
};
