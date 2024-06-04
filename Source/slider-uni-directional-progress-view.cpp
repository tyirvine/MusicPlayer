/*
  ==============================================================================

    SliderUniDirectionalProgressView.cpp
    Created: 3 Mar 2024 11:05:43pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "slider-uni-directional-progress-view.h"

//==============================================================================
SliderUniDirectionalProgressView::SliderUniDirectionalProgressView(float& leftValue, float& rightValue, std::function<void(float value)> listener)
    : slider(SliderType::UniDirectionalProgress, listener, "", &leftValue, &rightValue)
{
    addAndMakeVisible(slider);
}

SliderUniDirectionalProgressView::~SliderUniDirectionalProgressView()
{
}

void SliderUniDirectionalProgressView::resized()
{
    slider.setBounds(0, 0, getWidth(), getHeight());
}

void SliderUniDirectionalProgressView::setSliderValue(double value)
{
    slider.slider.setValue(value);
}
