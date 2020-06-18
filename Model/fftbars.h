#ifndef FFTBARS_H
#define FFTBARS_H

#include "Model/fft.h"

class FFTBars: public FFT
{

private:
    int sensitivity;
    int smoothing;
    std::vector<double> heights;

public:
    FFTBars();
    void setSensitivity(int);
    void setSmoothing(int);
    std::vector<double> run(std::complex<double>* f, unsigned int, unsigned int N, double d) override;
    std::vector<double> getHeights()const;
    void remapFFT(const std::vector<double>& ,double , double , double, double ) override;
};

#endif // FFTBARS_H
