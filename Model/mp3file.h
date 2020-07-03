#ifndef MP3FILE_H
#define MP3FILE_H

#include "Model/fileaudio.h"

class MP3File: public FileAudio
{
public:
    MP3File(const std::string&);
    virtual FileAudio* clone() const override;

    void setCoverArt(const QImage&);
    void setArtist(const std::string&);
    void setAlbum(const std::string&);
    void setGenre(const std::string&);
    void setMood(const std::string&);
    void setYear(unsigned int);
    void setBitrate(unsigned int);
    void setSampleRate(unsigned int);
    void setChannelCount(unsigned int);

    QImage getCoverArt()const;
    std::string getArtist() const;
    std::string getAlbum() const;
    std::string getGenre() const;
    std::string getMood() const;
    unsigned int getYear() const;
    unsigned int getBitrate() const;
    unsigned int getSampleRate() const;
    unsigned int getChannelCount() const;

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
