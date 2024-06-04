#include "main-layer.h"

//==============================================================================
MainLayer::MainLayer()
{
    // Here we set the size of the window on start.
    setSize(1512, 916);

    // Here we add in the presentation layer.
    addAndMakeVisible(presentationLayer);
}

void MainLayer::resized()
{
    // Pass down the window size to the presentation layer.
    presentationLayer.setBounds(getLocalBounds());
}
