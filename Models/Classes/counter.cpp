#include "counter.h"

Counter::Counter(unsigned int initialNumber)
{
    this->counter = initialNumber;
}


void Counter::AddPoint(unsigned int howMany)
{
    this->counter += howMany;
}

void Counter::SubtractPoint(unsigned int howMany)
{
    if(howMany > this->counter)
        this->counter = 0;
    else
        this->counter -= howMany;
}

void Counter::SetPoints(unsigned int howMany)
{
    this->counter = howMany;
}

unsigned int Counter::GetPoints()
{
    return this->counter;
}
