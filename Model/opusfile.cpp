#include "Model/opusfile.h"

OPUSFile::OPUSFile(const std::string& path): FileAudio (path), channelCount(0), samplerate(0){}


OPUSFile *OPUSFile::clone() const
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



