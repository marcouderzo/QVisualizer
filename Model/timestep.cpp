#include "Model/timestep.h"

TimeStep::TimeStep()
{
    ms=0;
}

void TimeStep::setTimeStep(unsigned int i)
{
    if(i<10 || i>100)
        throw Exceptions::OutOfRangeTimerValue();
    ms=i;
}

void TimeStep::startTimer()
{
    begin = std::chrono::steady_clock::now();
}

bool TimeStep::hasElapsed()
{
    end = std::chrono::steady_clock::now();
    return (std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() >= ms);
}
