#ifndef NOJSONERROR_H
#define NOJSONERROR_H

#include <exception>

class NoJsonError : public std::exception
{
public:
    NoJsonError();
    const char *what() const throw() override;
};

#endif // NOJSONERROR_H
