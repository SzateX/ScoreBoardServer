#include "game.h"
#include "Models/Classes/reversetimer.h"
#include "Models/Classes/team.h"
#include "Exceptions/clockkeyerror.h"
#include "Exceptions/teamkeyerror.h"

Game::Game() : period(Counter(1))
{
    this->teams["home"] = std::make_unique<Team, QString>(QString("Home Team"));
    this->teams["away"] = std::make_unique<Team, QString>(QString("Away Team"));
    this->clocks["primary"] = std::make_unique<ReverseTimer, int>(10);
    this->clocks["secondary"] = std::make_unique<ReverseTimer, int>(10);
}


ACounter &Game::GetPeriodCounter()
{
    return period;
}

ATeam &Game::GetTeam(const QString& key)
{
    if(teams.count(key))
        return *teams[key];
    throw TeamKeyError();
}

AReverseTimer &Game::GetClock(const QString &key)
{
    if(clocks.count(key))
        return *clocks[key];
    throw ClockKeyError();
}
