/*
  ==============================================================================

    SliderBiDirectionalVerticalView.h
    Created: 3 Mar 2024 11:05:07pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "slider-view.h"

//==============================================================================
/*
*/
class SliderBiDirectionalVerticalView : public juce::Component {
public:
    SliderBiDirectionalVerticalView(std::string label, std::function<void(float value)> listener);

    ~SliderBiDirectionalVerticalView() override;

    void paint(juce::Graphics&) override;

    void resized() override;
	
	void setSliderValue(double value);

private:
    SliderView slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderBiDirectionalVerticalView)
};
