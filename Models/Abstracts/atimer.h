#ifndef ATIMER_H
#define ATIMER_H


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
