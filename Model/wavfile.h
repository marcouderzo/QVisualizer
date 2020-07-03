#ifndef WAVFILE_H
#define WAVFILE_H

#include "Model/fileaudio.h"

class WAVFile : public FileAudio
{
public:
    WAVFile(const std::string&);
    virtual FileAudio* clone() const override;
    bool isLossless() const override;

    void setArtist(const std::string&);
    void setAlbum(const std::string&);
    void setGenre(const std::string&);
    void setYear(unsigned int);
    void setBitrate(unsigned int);
    void setSampleRate(unsigned int);
    void setChannelCount(unsigned int);

    std::string getArtist() const;
    std::string getAlbum() const;
    std::string getGenre() const;
    unsigned int getYear() const;
    unsigned int getBitrate() const;
    unsigned int getSampleRate() const;
    unsigned int getChannelCount() const;

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
