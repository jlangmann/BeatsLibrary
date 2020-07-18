#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <iostream>
#include <unordered_map>

#include "song.h"
#include "tag.h"

class Library
{

    typedef std::vector<Song> SongList;
    typedef std::unordered_map<std::string, Song> SongMap;

public:
    Library();
    void addSong(Song &song);
    void removeSong(Song song);

    SongList getSongs(const std::vector<Tag> tag = std::vector<Tag>());
    std::vector<std::string> getSongStrs(const std::vector<Tag> tag = std::vector<Tag>());

private:
    void initialize();

    SongMap m_songMap;
    SongList m_songList;

};


#endif // LIBRARY_H
