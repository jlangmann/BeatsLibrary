#include "include/song.h"

Song::Song(std::string name, std::string filepath)
{
    m_name = name;
    m_filepath = filepath;

}


std::string Song::name(){
    return m_name;
}


void Song::addTag(std::string tag)
{
    m_tagList.push_back(tag);
}


