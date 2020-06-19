#include "Model/flacfile.h"

FLACFile::FLACFile(const std::string& path): FileAudio (path), title(""), artist(""), album(""){}


FileAudio *FLACFile::clone() const
{
    return new FLACFile(*this);
}

std::string FLACFile::getTitle() const
{
    return title;
}

std::string FLACFile::getArtist() const
{
    return artist;
}

std::string FLACFile::getAlbum() const
{
    return album;
}

bool FLACFile::isLossless() const
{
    return true;
}

void FLACFile::setCoverArt(const QImage & image)
{
    coverArt = image;
}

QImage FLACFile::getCoverArt() const
{
    return coverArt;
}

void FLACFile::setTitle(const std::string& s)
{
    title=s;
}

void FLACFile::setArtist(const std::string& s)
{
    artist=s;
}

void FLACFile::setAlbum(const std::string& s)
{
    album=s;
}


