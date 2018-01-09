#ifndef GAME_H
#define GAME_H

#include <QString>
#include <map>
#include <memory>
#include "Models/Abstracts/agame.h"
#include "Models/Classes/counter.h"
#include "Models/Abstracts/ateam.h"
#include "Models/Abstracts/areversetimer.h"

class ACounter;

/*!
 * \brief The Game class. Implements AGame interface.
 */
class Game : public AGame
{
    /*!
     * \brief teams dictionary. Contains unique_ptr to ATeam objects. The keys are strings.
     */
    std::map<QString, std::unique_ptr<ATeam>> teams;
    /*!
     * \brief clocks dictionary. Containts unique_tre to AReverseTimer objects. The keys are strings.
     */
    std::map<QString, std::unique_ptr<AReverseTimer>> clocks;
    /*!
     * \brief period counter - counts period of game.
     */
    Counter period;
public:
    /*!
     * \brief Constructor of Game.
     */
    Game();

    // AGame interface
public:
    /*!
     * \brief GetPeriodCounter - method getting period counter.
     * \return Reference to ACounter which is period counter.
     */
    ACounter &GetPeriodCounter() override;
    /*!
     * \brief GetTeam - method getting Team object from teams dictionary
     * \param key - String with dictionary key. Have to be value like "home" or "away"
     * \return Reference to ATeam object
     * \throws TeamKeyError when key is not "home" or "away"
     */
    ATeam &GetTeam(const QString& key) override;
    /*!
     * \brief GetClock - method getting Clock object from clocks dictionary
     * \param key - String with dictionary key. Have to be value like "primary", "secondary"
     * \return Reference to AClock obejct
     * \throws ClockKeyError when key is not "primary", "secondary"
     */
    AReverseTimer &GetClock(const QString& key) override;
};

#endif // GAME_H
