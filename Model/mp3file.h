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
    void setGenre(const std::string&) override;
    void setMood(const std::string&) override;
    void setYear(unsigned int) override;
    void setBitrate(unsigned int) override;
    void setSampleRate(unsigned int) override;
    void setChannelCount(unsigned int) override;

    QImage getCoverArt()const override;
    std::string getArtist() const override;
    std::string getAlbum() const override;
    std::string getGenre() const override;
    std::string getMood() const override;
    unsigned int getYear() const override;
    unsigned int getBitrate() const override;
    unsigned int getSampleRate() const override;
    unsigned int getChannelCount() const override;

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
