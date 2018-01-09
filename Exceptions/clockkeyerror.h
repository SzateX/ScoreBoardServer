#ifndef CLOCKKEYERROR_H
#define CLOCKKEYERROR_H

#include <exception>

/*! Exception class for getter od clock

    Is throwed when there no exists clock key delivered in argument of method.
*/
class ClockKeyError : public std::exception
{
public:
    ClockKeyError();

    // exception interface
public:
    const char *what() const throw() override;
};

#endif // CLOCKKEYERROR_H
