#ifndef AIFFFile_H
#define AIFFFile_H

#include "Model/fileaudio.h"

class AIFFFile: public FileAudio
{
public:
    AIFFFile(const std::string&);
    virtual FileAudio* clone() const override;
    std::string getArtist() const override;
    std::string getAlbum() const override;
    void setCoverArt(const QImage&)override;
    QImage getCoverArt()const override;
    void setArtist(const std::string&)override;
    void setAlbum(const std::string&)override;
    bool isLossless() const override;
};

#endif // AIFFFile_H
