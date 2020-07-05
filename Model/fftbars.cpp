#include "Model/fftbars.h"

FFTBars::FFTBars():sensitivity(500), smoothing(1){}

void FFTBars::setSensitivity(int amt)
{
    sensitivity = amt;
}

void FFTBars::setSmoothing(int amt)
{
    smoothing=amt;
}

std::vector<double> FFTBars::run(std::complex<double> *f, unsigned int samples, unsigned int N, double d)
{
    setFrames(samples);
    zeroPad(f);
    runFFT(getFFTInputData(), N, d);
    smoothFFT(smoothing);
    remapFFT(getOutFrequencies(), 0, sensitivity, -1, 1);
    clearOutFrequencies();
    return heights;
}

std::vector<double> FFTBars::getHeights()const
{
    return heights;
}

void FFTBars::remapFFT(const std::vector<double> &freq, double oldBeg, double oldEnd, double newBeg, double newEnd)
{
    heights.clear();
    for(std::vector<double>::const_iterator it = freq.begin(); it < freq.end(); it++){

        //credits to processing.org
        double aux = newBeg + (newEnd - newBeg) * ((*it - oldBeg) / (oldEnd - oldBeg));
        heights.push_back(aux);
    }
}
