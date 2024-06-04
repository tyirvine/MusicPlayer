/*
  ==============================================================================

    SliderView.h
    Created: 3 Mar 2024 7:05:05pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "styles.h"

//==============================================================================

enum SliderType {
    UniDirectional,
    BiDirectional,
    BiDirectionalVertical,
    UniDirectionalProgress
};

class SliderView : public juce::Component {
public:
    SliderView(SliderType sliderType, std::function<void(float value)> listener, std::string label = NULL, float* leftValue = nullptr, float* rightValue = nullptr);

    ~SliderView() override;

    void paintOverChildren(juce::Graphics&) override;

    void paint(juce::Graphics&) override;

    void resized() override;

    juce::Slider slider {};

private:
    float value = 0.0f;

    SliderType sliderType;

    std::string label;

    float* leftValue;

    float* rightValue;

    juce::LookAndFeel* lookAndFeel;

    SliderUniLookAndFeel sliderUniLookAndFeel;

    SliderUniProgressLookAndFeel sliderUniProgressLookAndFeel;

    SliderBiLookAndFeel sliderBiLookAndFeel;

    SliderBiVerticalLookAndFeel sliderBiVerticalLookAndFeel;

    bool isBeingDragged;

    std::string formatTimeValue(int seconds);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderView)
};
