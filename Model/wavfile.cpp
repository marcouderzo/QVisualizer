#include "Model/wavfile.h"

WAVFile::WAVFile(const std::string& path): FileAudio (path), artist(""), album(""), genre(""), year(0), bitrate(0), samplerate(0), channelCount(0) {}

WAVFile *WAVFile::clone() const
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

std::string WAVFile::getGenre() const
{
    return genre;
}

unsigned int WAVFile::getYear() const
{
    return year;
}

unsigned int WAVFile::getBitrate() const
{
    return bitrate;
}

unsigned int WAVFile::getSampleRate() const
{
    return samplerate;
}

unsigned int WAVFile::getChannelCount() const
{
    return channelCount;
}

void WAVFile::setArtist(const std::string& s)
{
    artist=s;
}

void WAVFile::setAlbum(const std::string& s)
{
    album=s;
}

void WAVFile::setGenre(const std::string & g)
{
    genre = g;
}

void WAVFile::setYear(unsigned int y)
{
    year = y;
}

void WAVFile::setBitrate(unsigned int b)
{
    bitrate = b;
}

void WAVFile::setSampleRate(unsigned int s)
{
    samplerate = s;
}

void WAVFile::setChannelCount(unsigned int cc)
{
    channelCount = cc;
}
