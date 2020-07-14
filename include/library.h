#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "song.h"
#include "tag.h"

class Library
{

    typedef std::vector<Song> SongList;

public:
    Library();
    void addSong(Song song);
    void removeSong(Song song);

    SongList getSongs(const std::vector<Tag> tag);
};


#endif // LIBRARY_H
