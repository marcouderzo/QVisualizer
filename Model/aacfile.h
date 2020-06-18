#ifndef AACFILE_H
#define AACFILE_H

#include "Model/fileaudio.h"

class AACFile: public FileAudio
{
public:
    AACFile(const std::string&);
    virtual FileAudio* clone() const override;
    void setTitle(const std::string&)override;
    std::string getTitle() const override;
    std::string getArtist() const override;
    std::string getAlbum() const override;
    void setCoverArt(const QImage&)override;
    QImage getCoverArt()const override;
    void setArtist(const std::string&)override;
    void setAlbum(const std::string&)override;

 private:
    std::string title;
    std::string artist;
    std::string album;
    QImage coverArt;
};

#endif // AACFILE_H
