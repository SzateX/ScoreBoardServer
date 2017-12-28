#ifndef COUNTER_H
#define COUNTER_H

#include "Models/Abstracts/acounter.h"

class Counter : public ACounter
{
    unsigned int counter;
public:
    Counter(unsigned int initialNumber);

    // ACounter interface
public:
    void AddPoint(unsigned int howMany) override;
    void SubtractPoint(unsigned int howMany) override;
    void SetPoints(unsigned int howMany) override;
    unsigned int GetPoints() override;
};

#endif // COUNTER_H
