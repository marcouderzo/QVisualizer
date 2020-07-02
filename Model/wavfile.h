#ifndef WAVFILE_H
#define WAVFILE_H

#include "Model/fileaudio.h"

class WAVFile : public FileAudio
{
public:
    WAVFile(const std::string&);
    virtual FileAudio* clone() const override;
    bool isLossless() const override;

    void setCoverArt(const QImage&) override;
    QImage getCoverArt() const override;
    virtual std::string getMood() const override;
    virtual void setMood(const std::string&) override;

    std::string getArtist() const override;
    std::string getAlbum() const override;
    virtual std::string getGenre() const override;
    virtual unsigned int getYear() const override;
    virtual unsigned int getBitrate() const override;
    virtual unsigned int getSampleRate() const override;
    virtual unsigned int getChannelCount() const override;

    void setArtist(const std::string&) override;
    void setAlbum(const std::string&) override;
    virtual void setGenre(const std::string&) override;
    virtual void setYear(unsigned int) override;
    virtual void setBitrate(unsigned int) override;
    virtual void setSampleRate(unsigned int) override;
    virtual void setChannelCount(unsigned int) override;

 private:
    std::string artist;
    std::string album;
    std::string genre;
    unsigned int year;
    unsigned int bitrate;
    unsigned int samplerate;
    unsigned int channelCount;
};

#endif // WAVFILE_H
