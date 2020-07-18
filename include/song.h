#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>

class Song
{

public:
    Song(std::string name, std::string filepath);
    std::string name();
    void addTag(std::string);

private:
    std::string m_name;
    std::string m_filepath;
    std::vector<std::string> m_tagList;
};


#endif // SONG_H
