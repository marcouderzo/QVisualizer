#include "Model/wavfile.h"

WAVFile::WAVFile(const std::string& path): FileAudio (path), title(""), artist(""), album(""){}

FileAudio *WAVFile::clone() const
{
    return new WAVFile(*this);
}

std::string WAVFile::getArtist() const
{
    return artist;
}

std::string WAVFile::getAlbum() const
{
    return album;
}

bool WAVFile::isLossless() const
{
    return true;
}

void WAVFile::setCoverArt(const QImage & image)
{
    coverArt=image;
}

QImage WAVFile::getCoverArt() const
{
    return coverArt;
}

void WAVFile::setArtist(const std::string& s)
{
    artist=s;
}

void WAVFile::setAlbum(const std::string& s)
{
    album=s;
}
