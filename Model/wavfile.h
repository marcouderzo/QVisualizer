#ifndef WAVFILE_H
#define WAVFILE_H

#include "Model/fileaudio.h"

class WAVFile : public FileAudio
{
public:
    WAVFile(const std::string&);
    virtual FileAudio* clone() const override;
    void setTitle(const std::string&) override;
    std::string getTitle() const override;
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

#endif // WAVFILE_H
