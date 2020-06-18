#ifndef SOUNDWAVE_H
#define SOUNDWAVE_H

#include "Model/onda.h"

class SoundWave: public Onda
{
public:
    SoundWave();
    void setRemapFactor(int);
    void remapByFactor();
    virtual std::vector<double> run(std::complex<double>*, unsigned int, unsigned int, double) override;

private:
    std::vector<double> wave;
    double remapFactor;

};

#endif // SOUNDWAVE_H
