#include "Model/onda.h"

Onda::Onda()
{
    frames = 2304;//Dimensione del buffer su Linux
}

void Onda::setFrames(unsigned int f)
{
    frames = f;
}

unsigned int Onda::getFrames() const
{
    return frames;
}
