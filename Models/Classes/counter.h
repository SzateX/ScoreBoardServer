#ifndef COUNTER_H
#define COUNTER_H

#include "Models/Abstracts/acounter.h"

/*! Class of Counter. Implements ACounter interface.

    Class for counter like points, periods, and any sort of value. Values have to be unsigned.
*/

class Counter : public ACounter
{
    /*!
     * \brief private counter field.
     */
    unsigned int counter;
public:
    /*!
     * \brief Counter constructor
     * \param initialNumber inital number which shuld be on start counter. Have to be unsigned
     */
    Counter(unsigned int initialNumber);

    // ACounter interface
public:
    /*!
     * \brief Method adds points to counter.
     * \param howMany how many points should be added, have to be unsigned
     */
    void AddPoint(unsigned int howMany) override;
    /*!
     * \brief Method subtract points from counter.
     * \param howMany how many points should be subtract, have to be unsigned. If howMany is greater then value of counter - sets zero as value
     */
    void SubtractPoint(unsigned int howMany) override;
    /*!
     * \brief Method sets value into counter.
     * \param howMany how many points should be setted, have to be unsigned.
     */
    void SetPoints(unsigned int howMany) override;
    /*!
     * \brief GetPoints get value of counter.
     * \return unsigned int which represents value of counter.
     */
    unsigned int GetPoints() override;
};

#endif // COUNTER_H
