/*
  ==============================================================================

    SongModel.h
    Created: 7 Mar 2024 10:30:10pm
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SongModel {
public:
    SongModel(std::string title, juce::File, juce::URL url, std::string duration);

    std::string getTitle();
	
	juce::File getFile();

    juce::URL getURL();
	
	std::string getDuration();
	
	static bool compare(SongModel a, SongModel b);

private:
	std::string title;
	
	juce::File file;

	juce::URL url;
	
	std::string duration;
};
