#ifndef OPUSFile_H
#define OPUSFile_H

#include "Model/fileaudio.h"

class OPUSFile: public FileAudio
{
public:
    OPUSFile(const std::string&);
    virtual FileAudio* clone() const override;
    std::string getArtist() const override;
    std::string getAlbum() const override;
    bool isLossless() const override;
    void setCoverArt(const QImage&) override;
    QImage getCoverArt()const override;
    void setArtist(const std::string&) override;
    void setAlbum(const std::string&) override;

 private:
    std::string title;
    std::string artist;
    std::string album;
    QImage coverArt;
};

#endif // OPUSFile_H
