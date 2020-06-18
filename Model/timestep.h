#ifndef TIMESTEP_H
#define TIMESTEP_H

#include <chrono>
#include <vector>

class TimeStep
{
public:
    TimeStep();
    virtual ~TimeStep() = default;

    void setTimeStep(unsigned int t);
    void startTimer();
    bool hasElapsed();
    virtual void tick(std::vector<double>) = 0;

protected:
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    unsigned int ms;
};

#endif // TIMESTEP_H
