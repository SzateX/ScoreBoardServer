#ifndef INVALIDJSON_H
#define INVALIDJSON_H

#include <exception>

class InvalidJson : public std::exception
{
public:
    InvalidJson();
    const char *what() const throw() override;
};

#endif // INVALIDJSON_H
