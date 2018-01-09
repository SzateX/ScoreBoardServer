#ifndef REVERSETIMER_H
#define REVERSETIMER_H

#include <QTimer>
#include "Models/Abstracts/areversetimer.h"
#include "timer.h"

/*!
 * \brief The ReverseTimer class. Implements AReverseTimer interface, inherits from Timer class
 */
class ReverseTimer : public AReverseTimer, public Timer
{
    /*!
     * \brief maxSeconds variable which contains the value from should count timer.
     */
    double maxSeconds;
    /*!
     * \brief deffer object contains QTimer which async waits for end of counting
     */
    QTimer deffer;
    /*!
     * \brief ResetState - resets state of clock. Stops clock if running.
     */
    virtual void ResetState();
public:
    /*!
     * \brief ReverseTimer constructor
     * \param seconds parameter which said from what initial value should counter start counts.
     */
    ReverseTimer(double seconds);

    // AReverseTimer interface
public:
    /*!
     * \brief ResetClock method resets clock. Clock is resetting but not stopped.
     */
    void ResetClock() override;
    /*!
     * \brief GetRemainingSeconds method gets seconds which remains to end of counting.
     * \return seconds remained
     */
    double GetRemainingSeconds() override;
    /*!
     * \brief SetMaxSeconds method sets seconds from should count
     * \param seconds value from counter shout counts.
     */
    void SetMaxSeconds(double seconds) override;

    // ATimer interface
public:
    /*!
     * \brief Start do the same thing like in ATimer class
     */
    void Start() override;
    /*!
     * \brief End do the same thing like in ATimer class
     */
    void End() override;
};

#endif // REVERSETIMER_H
