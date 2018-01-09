#ifndef TEAMKEYERROR_H
#define TEAMKEYERROR_H

#include<exception>

/*! Exception class for getter od clock

    Is throwed when there no exists team key delivered in argument of method.
*/
class TeamKeyError : public std::exception
{
public:
    TeamKeyError();

    // exception interface
public:
    const char *what() const throw() override;
};

#endif // TEAMKEYERROR_H
