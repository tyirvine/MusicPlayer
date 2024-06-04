/*
  ==============================================================================

    AudioPlayer.h
    Created: 25 Jan 2024 11:01:30am
    Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "song-model.h"

class SongManager : public juce::Component {
public:
    SongManager();

    ~SongManager();

    std::vector<SongModel> getSongs();

    void loadSongs(std::function<void()> callback);

    void clearSongs();

private:
    std::vector<SongModel> songs {};

    juce::FileChooser fileChooser { "" };

    void storeURLsAsSongs(juce::Array<juce::File> files, juce::Array<juce::URL> urls);
	
	std::string getDurationFromFile(juce::File file);
	
	std::string formatSecondsValue(int seconds);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SongManager)
};
