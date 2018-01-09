#ifndef AREVERSETIMER_H
#define AREVERSETIMER_H

#include "Models/Abstracts/atimer.h"

/*! An interface for any ReverseTimer classes

    Provides methods for manipulation on reverse timer (timer which counts from top to bottom).
*/
class AReverseTimer
{
public:
    AReverseTimer();
    virtual void ResetClock() = 0;
    virtual double GetRemainingSeconds() = 0;
    virtual void SetMaxSeconds(double seconds) = 0;
    virtual void Start() = 0;
    virtual void End() = 0;
    virtual ~AReverseTimer();
};

#endif // AREVERSETIMER_H
