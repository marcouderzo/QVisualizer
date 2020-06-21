#include "Model/aifffile.h"

AIFFFile::AIFFFile(const std::string& path): FileAudio (path), title(""){}

FileAudio *AIFFFile::clone() const
{
    return new AIFFFile(*this);
}

std::string AIFFFile::getArtist() const
{
    return "AIFF Doesn't Support Metadata!";
}

std::string AIFFFile::getAlbum() const
{
    return "AIFF Doesn't Support Metadata!";
}

void AIFFFile::setCoverArt(const QImage & image) {}

QImage AIFFFile::getCoverArt()const
{
    return QImage(nullptr);
}

void AIFFFile::setArtist(const std::string& s) {}

void AIFFFile::setAlbum(const std::string &s) {}

bool AIFFFile::isLossless() const
{
    return true;
}
