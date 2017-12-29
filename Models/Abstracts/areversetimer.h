#ifndef AREVERSETIMER_H
#define AREVERSETIMER_H

#include "Models/Abstracts/atimer.h"

class AReverseTimer
{
public:
    AReverseTimer();
    virtual void ResetClock() = 0;
    virtual double GetRemainingSeconds() = 0;
    virtual void SetMaxSeconds(double seconds) = 0;
    virtual ~AReverseTimer();
};

#endif // AREVERSETIMER_H
