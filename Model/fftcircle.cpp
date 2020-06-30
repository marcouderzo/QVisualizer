#include "Model/fftcircle.h"

FFTCircle::FFTCircle()
{
    sensitivity=300;
}

void FFTCircle::remapFFT(const std::vector<double> &freq, double oldBeg, double oldEnd, double newBeg, double newEnd)
{
    radiuses.clear();
    for(std::vector<double>::const_iterator it = freq.begin(); it < freq.end(); it++){

        //credits to processing.org
        double aux = newBeg + (newEnd - newBeg) * ((*it - oldBeg) / (oldEnd - oldBeg));
        radiuses.push_back(aux);
    }
}

std::vector<double> FFTCircle::getRadiuses()const
{
    return radiuses;
}

std::vector<double> FFTCircle::run(std::complex<double> *f, unsigned int samples, unsigned int N, double d)
{
    setFrames(samples);
    zeroPad(f);
    runFFT(getFFTInputData(), N, d);
    remapFFT(getOutFrequencies(), 0, sensitivity, 0.1, 1);
    clearOutFrequencies();
    return radiuses;
}

void FFTCircle::setSensitivity(int amt)
{
    sensitivity = amt;
}
