#ifndef ATIMER_H
#define ATIMER_H

/*! An interface for any Timer classes

    Provides methods for manipulation on timer like, start, stop, and reset. This sort of timers should count from bottom to top
*/
class ATimer
{
public:
    ATimer();
    virtual void Start() = 0;
    virtual void End() = 0;
    virtual void ResetTimer() = 0;
    virtual double GetSeconds() = 0;
    virtual ~ATimer();
};

#endif // ATIMER_H
