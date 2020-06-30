#include "Model/fileaudio.h"

FileAudio::FileAudio(const std::string& path)
{
    filePath=path;
}

std::string FileAudio::getFilePath() const
{
    return filePath;
}

std::string FileAudio::getTitle() const
{
    return title;
}

unsigned long long FileAudio::getDuration() const
{
    return duration;
}

void FileAudio::setFilePath(const std::string& s)
{
    filePath=s;
}

void FileAudio::setDuration(unsigned long long i)
{
    duration=i;
}

bool FileAudio::isLossless() const
{
    return false;
}

void FileAudio::setTitle(const std::string & t)
{
    title=t;
}

bool FileAudio::operator == (const FileAudio &f) const
{
    return filePath == f.filePath;
}
