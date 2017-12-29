#ifndef ACOUNTER_H
#define ACOUNTER_H


class ACounter
{
public:
    ACounter();
    virtual void AddPoint(unsigned int howMany = 1) = 0;
    virtual void SubtractPoint(unsigned int howMany = 1) = 0;
    virtual void SetPoints(unsigned int howMany = 0) = 0;
    virtual unsigned int GetPoints() = 0;
    virtual ~ACounter();
};

#endif // ACOUNTER_H
