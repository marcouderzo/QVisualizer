#include "Model/aifffile.h"

AIFFFile::AIFFFile(const std::string& path): FileAudio (path), title(""){}

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
    return "Artist is not available";
}

std::string AIFFFile::getAlbum() const
{
    return "Artist is not available";
}

void AIFFFile::setCoverArt(const QImage & image) {}

QImage AIFFFile::getCoverArt()const
{
    return QImage(nullptr);
}

void AIFFFile::setTitle(const std::string& s) {}

void AIFFFile::setArtist(const std::string& s) {}

void AIFFFile::setAlbum(const std::string &s) {}

bool AIFFFile::isLossless() const
{
    return true;
}
