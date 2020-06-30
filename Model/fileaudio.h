#ifndef FILEAUDIO_H
#define FILEAUDIO_H

#include <string>
#include <QImage> //Including QImage in order to save Cover Art MetaData

class FileAudio
{
public:
    FileAudio(const std::string&);
    virtual FileAudio* clone() const = 0;
    virtual ~FileAudio() = default;

    std::string getFilePath() const;
    std::string getFilename() const;
    std::string getTitle() const;
    virtual std::string getArtist() const = 0;
    virtual std::string getAlbum() const = 0;
    virtual QImage getCoverArt()const = 0;
    unsigned long long getDuration() const;
    void setFilePath(const std::string&);
    void setDuration(unsigned long long);
    virtual bool isLossless() const;
    void setTitle(const std::string&);
    virtual void setArtist(const std::string&) = 0;
    virtual void setAlbum(const std::string&) = 0;
    virtual void setCoverArt(const QImage&) = 0;
    bool operator == (const FileAudio& )const;

private:
    std::string filePath;
    std::string title;
    unsigned long long duration;
};

#endif // FILEAUDIO_H
