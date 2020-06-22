#ifndef MP3FILE_H
#define MP3FILE_H

#include "Model/fileaudio.h"

class MP3File: public FileAudio
{
public:
    MP3File(const std::string&);
    virtual FileAudio* clone() const override;
    std::string getArtist() const override;
    std::string getAlbum() const override;
    void setCoverArt(const QImage&) override;
    QImage getCoverArt()const override;
    void setArtist(const std::string&) override;
    void setAlbum(const std::string&) override;

 private:
    std::string artist;
    std::string album;
    QImage coverArt;
};

#endif // MP3FILE_H
