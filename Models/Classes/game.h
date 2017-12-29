#ifndef GAME_H
#define GAME_H

#include <QString>
#include <map>
#include <memory>
#include "Models/Abstracts/agame.h"
#include "Models/Classes/counter.h"

class ACounter;
class ATeam;
class AReverseTimer;

class Game : AGame
{
    std::map<QString, std::unique_ptr<ATeam>> teams;
    std::map<QString, std::unique_ptr<AReverseTimer>> clocks;
    Counter period;
public:
    Game();

    // AGame interface
public:
    ACounter &GetPeriodCounter() override;
    ATeam &GetTeam(const QString& key) override;
    AReverseTimer &GetClock(const QString& key) override;
};

#endif // GAME_H
