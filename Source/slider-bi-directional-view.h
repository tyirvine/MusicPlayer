/*
  ==============================================================================

    SliderBiDirectionalView.h
    Created: 27 Feb 2024 6:37:58pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "slider-view.h"

//==============================================================================
/// This is a slider that starts in the centre and can go both ways resultig
/// in a range of -1.0 to 1.0.
class SliderBiDirectionalView : public juce::Component {
public:
    SliderBiDirectionalView(std::string label, std::function<void(float value)> listener);

    ~SliderBiDirectionalView() override;

    void resized() override;
	
	void setSliderValue(double value);

private:
    SliderView slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderBiDirectionalView)
};
