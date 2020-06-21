#include "Model/onda.h"

Onda::Onda()
{
    frames = 2304;
}

void Onda::setFrames(unsigned int f)
{
    frames = f;
}

unsigned int Onda::getFrames() const
{
    return frames;
}
