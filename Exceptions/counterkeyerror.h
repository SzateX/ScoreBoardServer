#ifndef COUNTERKEYERROR_H
#define COUNTERKEYERROR_H

#include <exception>

/*! Exception class for getter od clock

    Is throwed when there no exists counter key delivered in argument of method.
*/
class CounterKeyError : public std::exception
{
public:
    CounterKeyError();

    // exception interface
public:
    const char *what() const throw() override;
};

#endif // COUNTERKEYERROR_H
