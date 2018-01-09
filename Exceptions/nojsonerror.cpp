#include "nojsonerror.h"

NoJsonError::NoJsonError()
{

}

const char *NoJsonError::what() const throw ()
{
    return "This not json";
}
