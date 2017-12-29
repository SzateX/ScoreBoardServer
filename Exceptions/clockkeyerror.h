#ifndef CLOCKKEYERROR_H
#define CLOCKKEYERROR_H

#include <exception>

class ClockKeyError : public std::exception
{
public:
    ClockKeyError();

    // exception interface
public:
    const char *what() const throw() override;
};

#endif // CLOCKKEYERROR_H
