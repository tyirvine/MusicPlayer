/*
  ==============================================================================

    SliderBiDirectionalView.cpp
    Created: 27 Feb 2024 6:37:58pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "slider-bi-directional-view.h"

//==============================================================================
SliderBiDirectionalView::SliderBiDirectionalView(std::string label, std::function<void(float value)> listener)
    : slider(SliderType::BiDirectional, listener, label)
{
    addAndMakeVisible(slider);
}

SliderBiDirectionalView::~SliderBiDirectionalView()
{
}

void SliderBiDirectionalView::resized()
{
    slider.setBounds(0, 0, getWidth(), getHeight());
}

void SliderBiDirectionalView::setSliderValue(double value)
{
    slider.slider.setValue(value);
}
