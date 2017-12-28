#include "counterkeyerror.h"

CounterKeyError::CounterKeyError()
{

}


const char *CounterKeyError::what() const throw ()
{
    return "Only 'primary' or 'secondary' or 'tertiary' is permitted";
}
