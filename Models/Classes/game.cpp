#include "game.h"
#include "Models/Classes/reversetimer.h"
#include "Models/Classes/team.h"
#include "Exceptions/clockkeyerror.h"
#include "Exceptions/teamkeyerror.h"
#include <QDebug>

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
    //qDebug() << "Przyszedł mi ten team: " << key;
    if(teams.count(key))
        return *teams[key];
    //qDebug() << "Zaraz wyrzucę exception Team";
    throw TeamKeyError();
}

AReverseTimer &Game::GetClock(const QString &key)
{
    if(clocks.count(key))
        return *clocks[key];
    throw ClockKeyError();
}
