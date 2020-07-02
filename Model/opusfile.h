#ifndef OPUSFile_H
#define OPUSFile_H

#include "Model/fileaudio.h"

class OPUSFile: public FileAudio
{
public:
    OPUSFile(const std::string&);
    virtual FileAudio* clone() const override;
    bool isLossless() const override;

    virtual void setSampleRate(unsigned int) override;
    virtual void setChannelCount(unsigned int) override;

    virtual unsigned int getSampleRate() const override;
    virtual unsigned int getChannelCount() const override;


    void setCoverArt(const QImage&) override;
    QImage getCoverArt()const override;
    void setArtist(const std::string&) override;
    void setAlbum(const std::string&) override;
    virtual void setGenre(const std::string&) override;
    virtual void setMood(const std::string&) override;
    virtual void setYear(unsigned int) override;
    virtual void setBitrate(unsigned int) override;

    std::string getArtist() const override;
    std::string getAlbum() const override;
    virtual std::string getGenre() const override;
    virtual std::string getMood() const override;
    virtual unsigned int getYear() const override;
    virtual unsigned int getBitrate() const override;

 private:
    unsigned int channelCount;
    unsigned int samplerate;

};

#endif // OPUSFile_H
