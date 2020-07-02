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

    virtual std::string getArtist() const = 0;
    virtual std::string getAlbum() const = 0;
    virtual QImage getCoverArt()const = 0;
    virtual std::string getGenre() const = 0;
    virtual std::string getMood() const = 0;
    virtual unsigned int getYear() const = 0;
    virtual unsigned int getBitrate() const = 0;
    virtual unsigned int getSampleRate() const= 0;
    virtual unsigned int getChannelCount() const= 0;

    virtual void setArtist(const std::string&) = 0;
    virtual void setAlbum(const std::string&) = 0;
    virtual void setCoverArt(const QImage&) = 0;
    virtual void setGenre(const std::string&) = 0;
    virtual void setMood(const std::string&) = 0;
    virtual void setYear(unsigned int) = 0;
    virtual void setBitrate(unsigned int) = 0;
    virtual void setSampleRate(unsigned int) = 0;
    virtual void setChannelCount(unsigned int) = 0;

    bool operator == (const FileAudio& )const;

private:
    std::string filePath;
    std::string title;
    long long duration;
};

#endif // FILEAUDIO_H
