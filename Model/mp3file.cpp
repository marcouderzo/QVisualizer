#include "Model/mp3file.h"

MP3File::MP3File(const std::string& path): FileAudio(path), artist(""), album(""), coverArt(nullptr), genre(""), year(0), bitrate(0), samplerate(0), channelCount(0) {}

FileAudio *MP3File::clone() const
{
    return new MP3File(*this);
}

std::string MP3File::getArtist() const
{
    return artist;
}

std::string MP3File::getAlbum() const
{
    return album;
}

std::string MP3File::getGenre() const
{
    return genre;
}

std::string MP3File::getMood() const
{
    return mood;
}

unsigned int MP3File::getYear() const
{
    return year;
}

unsigned int MP3File::getBitrate() const
{
    return bitrate;
}

unsigned int MP3File::getSampleRate() const
{
    return samplerate;
}

unsigned int MP3File::getChannelCount() const
{
    return channelCount;
}

void MP3File::setCoverArt(const QImage & image)
{
    coverArt=image;
}

QImage MP3File::getCoverArt() const
{
    return coverArt;
}

void MP3File::setArtist(const std::string& s)
{
    artist=s;
}

void MP3File::setAlbum(const std::string& s)
{
    album=s;
}

void MP3File::setGenre(const std::string & g)
{
    genre = g;
}

void MP3File::setMood(const std::string & m)
{
    mood = m;
}

void MP3File::setYear(unsigned int y)
{
    year = y;
}

void MP3File::setBitrate(unsigned int b)
{
    bitrate = b;
}

void MP3File::setSampleRate(unsigned int s)
{
    samplerate = s;
}

void MP3File::setChannelCount(unsigned int cc)
{
    channelCount = cc;
}
