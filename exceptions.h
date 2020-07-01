#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<exception>

class Exceptions : public std::exception
{
public:
    class OutOfRangeTimerValue {};
    class OutOfRangeDuration {};
};

#endif // EXCEPTIONS_H
