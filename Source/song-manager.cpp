/*
  ==============================================================================

    AudioPlayer.cpp
    Created: 25 Jan 2024 11:01:30am
    Author:  Personal

  ==============================================================================
*/

#include "song-manager.h"

SongManager::SongManager()
{
}

SongManager::~SongManager()
{
}

std::vector<SongModel> SongManager::getSongs()
{
    return songs;
}

void SongManager::loadSongs(std::function<void()> callback)
{
    // Sets up the file chooser to choose a collection of songs.
    auto fileChooserFlags = juce::FileBrowserComponent::canSelectMultipleItems | juce::FileBrowserComponent::canSelectFiles;

    // Launches the file browser and then parses selected files and stores them.
    fileChooser.launchAsync(fileChooserFlags, [=](const juce::FileChooser& chooser) {
        juce::Array<juce::URL> urls { chooser.getURLResults() };
        juce::Array<juce::File> files { chooser.getResults() };
        storeURLsAsSongs(files, urls);
        callback();
    });
}

void SongManager::clearSongs()
{
    songs.clear();
}

void SongManager::storeURLsAsSongs(juce::Array<juce::File> files, juce::Array<juce::URL> urls)
{
    std::vector<SongModel> songsParsed {};

    // Iterate through the urls.
    for (int i = 0; i < urls.size(); i++) {

        // Get the properties of the song.
        juce::File file = files[i];
        juce::URL url = urls[i];
        juce::String titleUnparsed = url.getFileName();
        std::string titleParsed = juce::URL::removeEscapeChars(titleUnparsed).toStdString();

        // Erases the .mp3 off the end of each song.
        titleParsed.erase(titleParsed.end() - 4, titleParsed.end() + 4);
        std::string title = titleParsed;

        // Get the duration of the song.
        std::string duration = getDurationFromFile(file);

        // Construct the song object and add it.
        SongModel song = SongModel(title, file, url, duration);
        songsParsed.push_back(song);
    }

    // Store the parsed songs.
    songs = songsParsed;
}

// Reference available in the report. [9]
// https://forum.juce.com/t/get-track-length-before-it-starts-playing/44838/2
std::string SongManager::getDurationFromFile(juce::File file)
{
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();

    if (auto reader = formatManager.createReaderFor(file)) {
        auto lengthInSeconds = reader->lengthInSamples / reader->sampleRate;
        return formatSecondsValue(lengthInSeconds);
    }

    return "?";
}

std::string SongManager::formatSecondsValue(int seconds)
{
    // Here we grab the individual seconds and minutes units of a M:SS song time format.
    int secondsFormatted = seconds % 60;
    int minutesFormatted = floor(seconds / 60);

    std::string secondsFill = (secondsFormatted < 10) ? "0" : "";
    return std::to_string(minutesFormatted) + ":" + secondsFill + std::to_string(secondsFormatted);
}
