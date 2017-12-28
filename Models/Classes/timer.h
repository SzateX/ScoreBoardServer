#ifndef TIMER_H
#define TIMER_H

#include <QDateTime>
#include "Models/Abstracts/atimer.h"

class Timer : public ATimer
{
    double secondsFromLastAction;
    bool isEnabled;
    QDateTime timestamp;
public:
    Timer();

    // ATimer interface
public:
    virtual void Start();
    virtual void End();
    void ResetTimer() override;
    double GetSeconds() override;
};

#endif // TIMER_H
