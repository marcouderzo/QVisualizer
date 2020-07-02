#ifndef OPUSFile_H
#define OPUSFile_H

#include "Model/fileaudio.h"

class OPUSFile: public FileAudio
{
public:
    OPUSFile(const std::string&);
    virtual FileAudio* clone() const override;
    bool isLossless() const override;

    void setSampleRate(unsigned int) override;
    void setChannelCount(unsigned int) override;

    unsigned int getSampleRate() const override;
    unsigned int getChannelCount() const override;


    void setCoverArt(const QImage&) override;
    void setArtist(const std::string&) override;
    void setAlbum(const std::string&) override;
    void setGenre(const std::string&) override;
    void setMood(const std::string&) override;
    void setYear(unsigned int) override;
    void setBitrate(unsigned int) override;

    QImage getCoverArt()const override;
    std::string getArtist() const override;
    std::string getAlbum() const override;
    std::string getGenre() const override;
    std::string getMood() const override;
    unsigned int getYear() const override;
    unsigned int getBitrate() const override;

 private:
    unsigned int channelCount;
    unsigned int samplerate;

};

#endif // OPUSFile_H
