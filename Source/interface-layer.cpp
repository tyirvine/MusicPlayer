/*
  ==============================================================================

    InterfaceLayers.cpp
    Created: 9 Mar 2024 3:21:21pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "interface-layer.h"

//==============================================================================
InterfaceLayer::InterfaceLayer(StorageLayer& storageLayer)
{
	LogicInterface::instance().initialize(storageLayer);
}

InterfaceLayer::InterfaceLayer(LogicLayer& logicLayer)
{
	PresentationInterface::instance().initialize(logicLayer);
}
