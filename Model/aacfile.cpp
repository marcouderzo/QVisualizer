#include "Model/aacfile.h"

AACFile::AACFile(const std::string& path): FileAudio (path), title(""), artist(""), album(""){}

FileAudio *AACFile::clone() const
{
    return new AACFile(*this);
}

std::string AACFile::getTitle() const
{
    return title;
}

std::string AACFile::getArtist() const
{
    return artist;
}

std::string AACFile::getAlbum() const
{
    return album;
}

void AACFile::setCoverArt(const QImage & image)
{
    coverArt = image;
}

QImage AACFile::getCoverArt()const
{
    return coverArt;
}

void AACFile::setTitle(const std::string& s)
{
    title=s;
}

void AACFile::setArtist(const std::string& s)
{
    artist=s;
}

void AACFile::setAlbum(const std::string &s)
{
    album=s;
}
