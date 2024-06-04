/*
  ==============================================================================

    SliderUniDirectionalView.cpp
    Created: 27 Feb 2024 6:37:17pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "slider-uni-directional-view.h"

//==============================================================================
SliderUniDirectionalView::SliderUniDirectionalView(std::string label, std::function<void(float value)> listener)
    : slider(SliderType::UniDirectional, listener, label)
{
    addAndMakeVisible(slider);
}

SliderUniDirectionalView::~SliderUniDirectionalView()
{
}

void SliderUniDirectionalView::resized()
{
    slider.setBounds(0, 0, getWidth(), getHeight());
}

void SliderUniDirectionalView::setSliderValue(double value)
{
    slider.slider.setValue(value);
}
