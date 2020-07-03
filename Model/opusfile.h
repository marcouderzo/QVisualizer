#ifndef OPUSFile_H
#define OPUSFile_H

#include "Model/fileaudio.h"

class OPUSFile: public FileAudio
{
public:
    OPUSFile(const std::string&);
    virtual FileAudio* clone() const override;
    bool isLossless() const override;

    void setSampleRate(unsigned int);
    void setChannelCount(unsigned int);

    unsigned int getSampleRate() const;
    unsigned int getChannelCount() const;

 private:
    unsigned int channelCount;
    unsigned int samplerate;

};

#endif // OPUSFile_H
