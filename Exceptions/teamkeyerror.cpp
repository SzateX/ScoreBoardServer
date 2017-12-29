#include "teamkeyerror.h"

TeamKeyError::TeamKeyError()
{

}


const char *TeamKeyError::what() const throw()
{
    return "Only 'home' or 'away' key is permitted";
}
