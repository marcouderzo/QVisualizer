#include "Model/aifffile.h"

AIFFFile::AIFFFile(const std::string& path): FileAudio (path), title(""), artist(""), album(""){}

FileAudio *AIFFFile::clone() const
{
    return new AIFFFile(*this);
}

std::string AIFFFile::getTitle() const
{
    return title;
}

std::string AIFFFile::getArtist() const
{
    return artist;
}

std::string AIFFFile::getAlbum() const
{
    return album;
}

void AIFFFile::setCoverArt(const QImage & image)
{
    coverArt = image;
}

QImage AIFFFile::getCoverArt()const
{
    return coverArt;
}

void AIFFFile::setTitle(const std::string& s)
{
    title=s;
}

void AIFFFile::setArtist(const std::string& s)
{
    artist=s;
}

void AIFFFile::setAlbum(const std::string &s)
{
    album=s;
}
