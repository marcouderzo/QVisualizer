#ifndef MP3FILE_H
#define MP3FILE_H

#include "Model/fileaudio.h"

class MP3File: public FileAudio
{
public:
    MP3File(const std::string&);
    virtual FileAudio* clone() const override;

    void setCoverArt(const QImage&) override;
    void setArtist(const std::string&) override;
    void setAlbum(const std::string&) override;
    virtual void setGenre(const std::string&) override;
    virtual void setMood(const std::string&) override;
    virtual void setYear(unsigned int) override;
    virtual void setBitrate(unsigned int) override;
    virtual void setSampleRate(unsigned int) override;
    virtual void setChannelCount(unsigned int) override;

    QImage getCoverArt()const override;
    std::string getArtist() const override;
    std::string getAlbum() const override;
    virtual std::string getGenre() const override;
    virtual std::string getMood() const override;
    virtual unsigned int getYear() const override;
    virtual unsigned int getBitrate() const override;
    virtual unsigned int getSampleRate() const override;
    virtual unsigned int getChannelCount() const override;

 private:
    std::string artist;
    std::string album;
    QImage coverArt;
    std::string genre;
    std::string mood;
    unsigned int year;
    unsigned int bitrate;
    unsigned int samplerate;
    unsigned int channelCount;
};

#endif // MP3FILE_H
