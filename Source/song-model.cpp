/*
  ==============================================================================

    SongModel.cpp
    Created: 7 Mar 2024 10:30:10pm
    Author:  Personal

  ==============================================================================
*/

#include <JuceHeader.h>
#include "song-model.h"

//==============================================================================
SongModel::SongModel(std::string title, juce::File file, juce::URL url, std::string duration)
    : title(title)
    , file(file)
    , url(url)
    , duration(duration)
{
}

std::string SongModel::getTitle()
{
    return title;
}

juce::File SongModel::getFile()
{
    return file;
}

juce::URL SongModel::getURL()
{
    return url;
}

std::string SongModel::getDuration()
{
    return duration;
}

bool SongModel::compare(SongModel a, SongModel b) {
	return (a.title > b.title);
}
