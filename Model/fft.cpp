#include "Model/fft.h"

FFT::FFT()
{
    outFrequencies.reserve(4096);
}

void FFT::smoothFFT(int value)
{
    if(value==1)
    {
        for(unsigned int i=0; i<4096; i++)
        {
            if(i!=0)
                outFrequencies[i]=(outFrequencies[i]+outFrequencies[i-1])/2;
        }
    }
    if(value==2)
    {
        for(unsigned int i=0; i<4096; i++)
        {
            if(i==1)
               outFrequencies[i]=(outFrequencies[i]+outFrequencies[i-1])/2;
            else if(i>=2)
                outFrequencies[i]=(outFrequencies[i]+outFrequencies[i-1]+outFrequencies[i-2])/3;
        }
    }
}

void FFT::setOutFrequencies(std::complex<double>* fft)
{
    outFrequencies.clear();
    for(int i = 0; i < 4096; i++){
        outFrequencies.push_back(std::abs(fft[i]));
    }
}

std::vector<double> FFT::getOutFrequencies() const
{
    return outFrequencies;
}

int FFT::reverse(unsigned int N, unsigned int n) const
{
    int j, p = 0;
    for(j = 1; j <= static_cast<int>(log2(N)); j++) {
        if(n & (1 << (static_cast<int>(log2(N)) - j))){
            p |= 1 << (j - 1);
        }
    }
    return p;
}

void FFT::sort(std::complex<double>* f1, unsigned int N) const
{
    std::complex<double> f2[MAX];
    for(unsigned int i = 0; i < N; i++){
        f2[i] = f1[reverse(N, i)];
    }
    for(unsigned int j = 0; j < N; j++){
        f1[j] = f2[j];
    }
}

void FFT::transform(std::complex<double>* f, unsigned int N) const
{
    sort(f, N);
    std::complex<double>* W = new std::complex<double> [N / 2];
    W[1] = std::polar(1., -2. * M_PI / N);
    W[0] = 1;
    for(unsigned int i = 2; i < N / 2; i++){
        W[i] = pow(W[1], i);
    }
    unsigned int n = 1;
    unsigned int a = N / 2;
    for(unsigned int j = 0; j < log2(N); j++) {
        for(unsigned int i = 0; i < N; i++) {
            if(!(i & n)) {
                std::complex<double> temp = f[i];
                std::complex<double> Temp = W[(i * a) % (n * a)] * f[i + n];
                f[i] = temp + Temp;
                f[i + n] = temp - Temp;
            }
        }
        n *= 2;
        a = a / 2;
    }
    delete [] W;
}

void FFT::clearOutFrequencies(){
    outFrequencies.clear();
}

std::complex<double>* FFT::getFFTInputData()
{
    return FFTInputData;
}

void FFT::runFFT(std::complex<double>* f, unsigned int N, double d)
{
    transform(f, N);
    for(unsigned int i = 0; i < N; i++){
        f[i] *= d;
    }
    setOutFrequencies(f);
}

void FFT::zeroPad(std::complex<double>* toInterpolate)
{
    for(unsigned int i=0; i<getFrames(); i++)
        FFTInputData[i] = toInterpolate[i];

    for(unsigned int i=getFrames(); i<4096; i++)
        FFTInputData[i] = 0;
}
