#include "clockkeyerror.h"

ClockKeyError::ClockKeyError()
{

}


const char *ClockKeyError::what() const throw()
{
    return "Only 'primary' or 'secondary' key is permitted";
}
