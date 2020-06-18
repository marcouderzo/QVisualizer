#ifndef FFTCIRCLE_H
#define FFTCIRCLE_H

#include "Model/fft.h"

class FFTCircle : public FFT{

private:
    std::vector<double> radiuses;
    std::vector<double> freq;
    int sensitivity;

public:

    FFTCircle();
    void remapFFT(const std::vector<double>&, double, double, double, double) override;
    std::vector<double> getRadiuses() const;
    virtual std::vector<double> run(std::complex<double>*, unsigned int, unsigned int, double) override;
    void setSensitivity(int);
};

#endif // FFTCIRCLE_H
