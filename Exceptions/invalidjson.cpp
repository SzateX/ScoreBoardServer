#include "invalidjson.h"

InvalidJson::InvalidJson()
{

}

const char *InvalidJson::what() const throw()
{
    return "Json is invalid";
}
