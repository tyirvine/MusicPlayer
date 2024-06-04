/*
  ==============================================================================

	StateRelay.cpp
	Created: 27 Feb 2024 7:03:53pm
	Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "logic-interface.h"

//==============================================================================
void LogicInterface::initialize(StorageLayer& storageLayerReference)
{
    storageLayer = &storageLayerReference;
}
