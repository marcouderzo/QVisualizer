#include "Model/opusfile.h"

OPUSFile::OPUSFile(const std::string& path): FileAudio (path), channelCount(0), samplerate(0){}


FileAudio *OPUSFile::clone() const
{
    return new OPUSFile(*this);
}

bool OPUSFile::isLossless() const
{
    return true;
}

unsigned int OPUSFile::getSampleRate() const
{
    return samplerate;
}

unsigned int OPUSFile::getChannelCount() const
{
    return channelCount;
}

void OPUSFile::setSampleRate(unsigned int s)
{
    samplerate = s;
}

void OPUSFile::setChannelCount(unsigned int cc)
{
    channelCount = cc;
}



void OPUSFile::setArtist(const std::string&){}
void OPUSFile::setAlbum(const std::string&) {}
void OPUSFile::setGenre(const std::string &) {}
void OPUSFile::setMood(const std::string &) {}
void OPUSFile::setYear(unsigned int) {}
void OPUSFile::setBitrate(unsigned int) {}
void OPUSFile::setCoverArt(const QImage &){}

std::string OPUSFile::getArtist() const { return ""; }
std::string OPUSFile::getAlbum() const { return ""; }
std::string OPUSFile::getGenre() const { return ""; }
std::string OPUSFile::getMood() const { return ""; }
unsigned int OPUSFile::getYear() const { return 0; }
unsigned int OPUSFile::getBitrate() const { return 0; }
QImage OPUSFile::getCoverArt() const { return QImage(nullptr); }




