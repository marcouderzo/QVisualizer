#include "Model/onda.h"

Onda::Onda()
{
    //frames = 2304;
    frames = 3840;
}

void Onda::setFrames(unsigned int f)
{
    frames = f;
}

unsigned int Onda::getFrames() const
{
    return frames;
}
