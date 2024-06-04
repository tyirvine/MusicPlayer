#pragma once

#include <JuceHeader.h>
#include "presentation-layer.h"
#include "presentation-interface.h"
#include "logic-layer.h"
#include "logic-interface.h"
#include "storage-layer.h"
#include "interface-layer.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainLayer : public juce::Component {
public:
    MainLayer();

    void resized() override;

private:
    StorageLayer storageLayer {};

    InterfaceLayer logicInterfaceLayer { storageLayer };

    LogicLayer logicLayer {};

    InterfaceLayer presentationInterfaceLayer { logicLayer };

    PresentationLayer presentationLayer {};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainLayer)
};
