#include "Model/opusfile.h"

OPUSFile::OPUSFile(const std::string& path): FileAudio (path), artist(""), album(""){}


FileAudio *OPUSFile::clone() const
{
    return new OPUSFile(*this);
}

std::string OPUSFile::getArtist() const
{
    return artist;
}

std::string OPUSFile::getAlbum() const
{
    return album;
}

bool OPUSFile::isLossless() const
{
    return true;
}

void OPUSFile::setCoverArt(const QImage & image)
{
    coverArt = image;
}

QImage OPUSFile::getCoverArt() const
{
    return coverArt;
}

void OPUSFile::setArtist(const std::string& s)
{
    artist=s;
}

void OPUSFile::setAlbum(const std::string& s)
{
    album=s;
}


