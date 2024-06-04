/*
  ==============================================================================

    InterfaceLayers.h
    Created: 9 Mar 2024 3:21:21pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "storage-layer.h"
#include "logic-layer.h"
#include "presentation-layer.h"
#include "logic-interface.h"
#include "presentation-layer.h"

//==============================================================================
/*
*/
class InterfaceLayer {
public:
    InterfaceLayer(StorageLayer& storageLayer);
	
	InterfaceLayer(LogicLayer& logicLayer);
};
