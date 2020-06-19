#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<exception>

class Exceptions : public std::exception
{
public:

    class OutOfRangeTimerValue {};

};

#endif // EXCEPTIONS_H
