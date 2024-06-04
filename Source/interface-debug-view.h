/*
  ==============================================================================

    InterfaceDebugView.h
    Created: 27 Feb 2024 8:49:04pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "button-raised-view.h"
#include "button-flat-view.h"
#include "slider-uni-directional-view.h"
#include "slider-uni-directional-progress-view.h"
#include "slider-bi-directional-view.h"
#include "slider-bi-directional-vertical-view.h"
#include "search-raised-view.h"
#include "bottom-bar-view.h"
#include "audio-level-view.h"
#include "styles.h"

//==============================================================================
/// This view is for debugging mostly universal views and is only present in the debug
/// build of the project.
class InterfaceDebugView : public juce::Component {
public:
    InterfaceDebugView();

    ~InterfaceDebugView() override;

    void paint(juce::Graphics&) override;

    void resized() override;

private:
    ButtonRaisedView buttonRaisedView { "Eject", "􁏏", [=] { std::cout << "interface-debug-view.h Button Raised View Click" << std::endl; } };

    ButtonFlatView buttonFlatView { "􀆄", [=] { std::cout << "interface-debug-view.h Button Flat View Click" << std::endl; } };

    SliderUniDirectionalView sliderUniDirectionalView { "Volume", [](float value) { std::cout << "interface-debug-view.h Slider Uni Directional Value Change: " << value << std::endl; } };

    float leftValue = 39;

    float rightValue = 219;

    SliderUniDirectionalProgressView sliderUniDirectionalProgressView { leftValue, rightValue, [](float value) { std::cout << "interface-debug-view.h Slider Uni Directional Progress Value Change: " << value << std::endl; } };

    SliderBiDirectionalView sliderBiDirectionalView { "Speed", [](float value) { std::cout << "interface-debug-view.h Slider Bi Directional Value Change: " << value << std::endl; } };

    SliderBiDirectionalVerticalView sliderBiDirectionalVerticalView { "High", [](float value) { std::cout << "interface-debug-view.h Slider Bi Directional Vertical Value Change: " << value << std::endl; } };

    SearchRaisedView searchRaisedView { [=] { std::cout << "interface-debug-view.h Search Listener" << std::endl; } };

    BottomBarView bottomBarView { "37 Songs • 482 MB", STYLE_COLOR_LIBRARY_BACKING_BAR, STYLE_COLOR_LIBRARY_DIVIDER_BAR, STYLE_COLOR_LIBRARY_TEXT_BAR };

    AudioLevelView audioLevelView {};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InterfaceDebugView)
};
