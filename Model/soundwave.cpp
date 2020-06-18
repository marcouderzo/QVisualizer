#include "Model/soundwave.h"

SoundWave::SoundWave()
{
    remapFactor=1;
}

void SoundWave::setRemapFactor(int f)
{
    remapFactor = f/10.0;
}

void SoundWave::remapByFactor()
{
    for(std::vector<double>::iterator it = wave.begin(); it!=wave.end(); it++)
    {
        *it = *(it) * remapFactor;
    }
}

std::vector<double> SoundWave::run(std::complex<double> * vect, unsigned int samples, unsigned int n, double d)
{
    setFrames(samples);
    wave.clear();
    for(unsigned int i=0; i<getFrames(); i++)
        wave.push_back(real(vect[i]));

    remapByFactor();
    return wave;
}
