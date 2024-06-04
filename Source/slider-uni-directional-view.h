/*
  ==============================================================================

    SliderUniDirectionalView.h
    Created: 27 Feb 2024 6:37:17pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "slider-view.h"
#include "styles.h"

//==============================================================================
/// This is a slider that has a fill that goes in one direction.
class SliderUniDirectionalView : public juce::Component {
public:
    SliderUniDirectionalView(std::string label, std::function<void(float value)> listener);

    ~SliderUniDirectionalView() override;

    void resized() override;
	
	void setSliderValue(double value);

private:
    SliderView slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderUniDirectionalView)
};
