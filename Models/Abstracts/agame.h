#ifndef AGAME_H
#define AGAME_H

#include <map>
#include <QString>

class ACounter;
class ATeam;
class AReverseTimer;

/*! An interface for any Game classes

    Provides methods for getting any sort of Game elements like counters, teams, and timers, which can be used for further use.
*/
class AGame
{
public:
    AGame();
    virtual ACounter& GetPeriodCounter() = 0;
    virtual ATeam& GetTeam(const QString& key) = 0;
    virtual AReverseTimer& GetClock(const QString& key) = 0;
    virtual ~AGame();
};

#endif // AGAME_H
