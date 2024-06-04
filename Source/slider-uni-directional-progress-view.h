/*
  ==============================================================================

    SliderUniDirectionalProgressView.h
    Created: 3 Mar 2024 11:05:43pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "slider-view.h"

//==============================================================================
/*
*/
class SliderUniDirectionalProgressView : public juce::Component {
public:
    SliderUniDirectionalProgressView(float& leftValue, float& rightValue, std::function<void(float value)> listener);

    ~SliderUniDirectionalProgressView() override;

    void resized() override;

    void setSliderValue(double value);

private:
    SliderView slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderUniDirectionalProgressView)
};
