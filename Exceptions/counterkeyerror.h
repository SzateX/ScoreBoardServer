#ifndef COUNTERKEYERROR_H
#define COUNTERKEYERROR_H

#include <exception>

class CounterKeyError : public std::exception
{
public:
    CounterKeyError();

    // exception interface
public:
    const char *what() const throw() override;
};

#endif // COUNTERKEYERROR_H
