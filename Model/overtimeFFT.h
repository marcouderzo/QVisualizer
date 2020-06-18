#ifndef OVERTIMEFFT_H
#define OVERTIMEFFT_H

#include "Model/fft.h"
#include "Model/timestep.h"

class OvertimeFFT: public FFT, public TimeStep
{
public:

    OvertimeFFT();
    void tick(std::vector<double>) override;
    virtual void remapFFT(const std::vector<double>& ,double, double, double, double) override;
    void smoothTimeBuffer();
    std::vector<double> run(std::complex<double>* f, unsigned int,  unsigned int N, double d) override;
    std::vector<std::vector<double>> getTimeBuffer();
    void setSmoothing(int);
    void setSmoothLimit(unsigned int);

private:
    int smoothing;
    unsigned int smoothLimit;
    std::vector<std::vector<double>> timeBuffer;
    std::vector<double> heights;
};

#endif
