#ifndef FILEAUDIO_H
#define FILEAUDIO_H

#include <string>
#include <QImage> //Including QImage in order to save Cover Art MetaData

#include "exceptions.h"

class FileAudio
{
public:
    FileAudio(const std::string&);
    virtual FileAudio* clone() const = 0;
    virtual ~FileAudio() = default;

    void setFilePath(const std::string&);
    void setDuration(long long);
    void setTitle(const std::string&);

    std::string getFilePath() const;
    long long getDuration() const;
    std::string getTitle() const;
    virtual bool isLossless() const;

    bool operator == (const FileAudio& )const;

private:
    std::string filePath;
    std::string title;
    long long duration;
};

#endif // FILEAUDIO_H
