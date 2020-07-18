#include "include/library.h"

Library::Library()
{

    initialize();
}

void Library::initialize()
{
    Song *song = new Song("blah", "awefewf");

    m_songMap.insert({"test1", *song});
}


void Library::addSong(Song &song){
    std::cout << "adding song!" << std::endl;
    m_songMap.insert({song.name(), song});
}

void Library::removeSong(Song song){
    std::string name = song.name();
    if (m_songMap.find(name) != m_songMap.end())
    {
        m_songMap.erase(m_songMap.find(name));
    }
}


std::vector<Song> Library::getSongs(const std::vector<Tag> tag){
    SongList songs;
    return songs;
}


std::vector<std::string> Library::getSongStrs(const std::vector<Tag> tag){
    std::vector<std::string> output;
    for (std::pair<std::string, Song> element: m_songMap)
    {
        output.push_back(element.first);
    }
    return output;
}
