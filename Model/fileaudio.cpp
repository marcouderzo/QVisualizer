#include "Model/fileaudio.h"

FileAudio::FileAudio(const std::string& path)
{
    filePath=path;
}

std::string FileAudio::getFilePath() const
{
    return filePath;
}

unsigned int FileAudio::getDuration() const
{
    return duration;
}

void FileAudio::setFilePath(const std::string& s)
{
    filePath=s;
}

void FileAudio::setDuration(unsigned int i)
{
    duration=i;
}

bool FileAudio::isLossless() const
{
    return false;
}
