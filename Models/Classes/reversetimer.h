#ifndef REVERSETIMER_H
#define REVERSETIMER_H

#include <QTimer>
#include "Models/Abstracts/areversetimer.h"
#include "timer.h"

class ReverseTimer : public AReverseTimer, public Timer
{
    double maxSeconds;
    QTimer deffer;
    virtual void ResetState();
public:
    ReverseTimer(double seconds);

    // AReverseTimer interface
public:
    void ResetClock() override;
    double GetRemainingSeconds() override;
    void SetMaxSeconds(double seconds) override;

    // ATimer interface
public:
    void Start() override;
    void End() override;
};

#endif // REVERSETIMER_H
