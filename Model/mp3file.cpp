#include "Model/mp3file.h"

MP3File::MP3File(const std::string& path): FileAudio(path), title(""), artist(""), album(""){}

FileAudio *MP3File::clone() const
{
    return new MP3File(*this);
}

std::string MP3File::getTitle() const
{
    return title;
}

std::string MP3File::getArtist() const
{
    return artist;
}

std::string MP3File::getAlbum() const
{
    return album;
}

void MP3File::setCoverArt(const QImage & image)
{
    coverArt=image;
}

QImage MP3File::getCoverArt() const
{
    return coverArt;
}

void MP3File::setTitle(const std::string& s)
{
    title=s;
}

void MP3File::setArtist(const std::string& s)
{
    artist=s;
}

void MP3File::setAlbum(const std::string& s)
{
    album=s;
}
