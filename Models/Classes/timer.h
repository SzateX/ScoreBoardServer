#ifndef TIMER_H
#define TIMER_H

#include <QDateTime>
#include "Models/Abstracts/atimer.h"

/*!
 * \brief The Timer class. Implements ATimer interface.
 */
class Timer : public ATimer
{
    /*!
     * \brief secondsFromLastAction contains seconds which have elapsed from last end event.
     */
    double secondsFromLastAction;
    /*!
     * \brief isEnabled contains information about state of timer. Is running or not.
     */
    bool isEnabled;
    /*!
     * \brief timestamp contains timestamp of start timer.
     */
    QDateTime timestamp;
public:
    /*!
     * \brief Timer constructor
     */
    Timer();

    // ATimer interface
public:
    /*!
     * \brief Start method starts timer
     */
    virtual void Start();
    /*!
     * \brief End method stops timer
     */
    virtual void End();
    /*!
     * \brief ResetTimer method resets timer
     */
    void ResetTimer() override;
    /*!
     * \brief GetSeconds get seconds counted on timer
     * \return number of seconds which elapsed
     */
    double GetSeconds() override;
};

#endif // TIMER_H
