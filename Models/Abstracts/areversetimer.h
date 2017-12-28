#ifndef AREVERSETIMER_H
#define AREVERSETIMER_H


class AReverseTimer
{
public:
    AReverseTimer();
    virtual void ResetClock() = 0;
    virtual double GetRemainingSeconds() = 0;
    virtual void SetMaxSeconds(double seconds) = 0;
};

#endif // AREVERSETIMER_H
