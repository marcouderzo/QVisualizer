#ifndef WAVFILE_H
#define WAVFILE_H

#include "Model/fileaudio.h"

class WAVFile : public FileAudio
{
public:
    WAVFile(const std::string&);
    virtual FileAudio* clone() const override;
    bool isLossless() const override;

    std::string getArtist() const override;
    std::string getAlbum() const override;
    std::string getGenre() const override;
    unsigned int getYear() const override;
    unsigned int getBitrate() const override;
    unsigned int getSampleRate() const override;
    unsigned int getChannelCount() const override;

    void setArtist(const std::string&) override;
    void setAlbum(const std::string&) override;
    void setGenre(const std::string&) override;
    void setYear(unsigned int) override;
    void setBitrate(unsigned int) override;
    void setSampleRate(unsigned int) override;
    void setChannelCount(unsigned int) override;


    void setCoverArt(const QImage&) override;
    QImage getCoverArt() const override;
    void setMood(const std::string&) override;
    std::string getMood() const override;

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
