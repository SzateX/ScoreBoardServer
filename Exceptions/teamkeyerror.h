#ifndef TEAMKEYERROR_H
#define TEAMKEYERROR_H

#include<exception>

class TeamKeyError : public std::exception
{
public:
    TeamKeyError();

    // exception interface
public:
    const char *what() const throw() override;
};

#endif // TEAMKEYERROR_H
