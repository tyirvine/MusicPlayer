/*
  ==============================================================================

    StateRelay.h
    Created: 27 Feb 2024 7:03:53pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "storage-layer.h"

//==============================================================================
/*
*/
class LogicInterface {
public:
    static LogicInterface& instance()
    {
        static LogicInterface instance;
        return instance;
    }

    void initialize(StorageLayer& storageLayer);

private:
    StorageLayer* storageLayer { nullptr };

    LogicInterface() {};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LogicInterface)
};
