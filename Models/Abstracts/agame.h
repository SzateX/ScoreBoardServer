#ifndef AGAME_H
#define AGAME_H

#include <map>
#include <QString>

class ACounter;
class ATeam;
class AReverseTimer;

class AGame
{
public:
    AGame();
    virtual ACounter& GetPeriodCounter() = 0;
    virtual ATeam& GetTeam(const QString& key) = 0;
    virtual AReverseTimer& GetClock(const QString& key) = 0;
};

#endif // AGAME_H
