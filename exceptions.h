#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


class Exceptions
{
public:
    Exceptions();

    class UnsupportedFormat {};
    class MediaLoadingError {};
    class OutOfRangeTimerValue {};

};

#endif // EXCEPTIONS_H
