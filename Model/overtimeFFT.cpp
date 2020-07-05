#include "Model/overtimeFFT.h"

OvertimeFFT::OvertimeFFT():smoothing(0), smoothLimit(0){}

void OvertimeFFT::tick(std::vector<double> vect)
{
    if(timeBuffer.size() == 100 )
    {
        timeBuffer.pop_back();
    }
    timeBuffer.insert(timeBuffer.begin(), vect);

    if(smoothing!=0)
        smoothTimeBuffer();
}

std::vector<double> OvertimeFFT::run(std::complex<double> *f, unsigned int samples, unsigned int N, double d)
{
    setFrames(samples);
    zeroPad(f);
    runFFT(getFFTInputData(), N, d);
    smoothFFT(1);
    remapFFT(getOutFrequencies(), 0, 120, -1, 0.1);
    clearOutFrequencies();
    if(hasElapsed())
    {
        tick(heights);
        startTimer();
    }
    return heights;
}

std::vector<std::vector<double> > OvertimeFFT::getTimeBuffer()
{
    return timeBuffer;
}

void OvertimeFFT::setSmoothing(int amt)
{
    smoothing=amt;
}

void OvertimeFFT::setSmoothLimit(unsigned int amt)
{
    smoothLimit = amt;
}

void OvertimeFFT::remapFFT(const std::vector<double>& freq, double oldBeg, double oldEnd,  double newBeg, double newEnd){
    heights.clear();
    for(std::vector<double>::const_iterator it = freq.begin(); it < freq.end(); it++){

        //credits to processing.org
        double aux = newBeg + ((newEnd - oldBeg) * (*it - oldBeg) / (oldEnd - oldBeg));
        heights.push_back(aux);
    }
}

void OvertimeFFT::smoothTimeBuffer()
{
    if(smoothing==1)
    {
        if(timeBuffer.size() > 1)
            for(unsigned int i=0; i<timeBuffer.size(); i++)
                timeBuffer[0][i] = (timeBuffer[0][i]+timeBuffer[1][i])/2;
    }

    if(smoothing==2)
    {
        if(timeBuffer.size() < 100) return;
        for(unsigned int i=1; i<timeBuffer.size()-smoothLimit; i++)
            for(unsigned int k=0; k<100; k++)
                timeBuffer[i][k] = (timeBuffer[i][k]+timeBuffer[i-1][k])/2;
    }
}


