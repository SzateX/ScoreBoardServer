#include "team.h"
#include "Exceptions/counterkeyerror.h"
#include "Models/Abstracts/acounter.h"
#include "Models/Classes/counter.h"
#include <QDebug>

Team::Team(QString teamName)
{
    this->name = teamName;
    timeoutFlag = false;
    penaltyFlag = false;
    counters["primary"] = std::make_unique<Counter, int>(0);
    counters["secondary"] = std::make_unique<Counter, int>(0);
    counters["tertiary"] = std::make_unique<Counter, int>(0);
}


void Team::SetName(const QString &name)
{
    this->name = name;
}

QString Team::GetName()
{
    return this->name;
}

ACounter& Team::GetCounter(const QString &key)
{
    //qDebug() << "Zbieram counter: " << key;
    if(counters.count(key))
        return *counters[key];
    //qDebug() << "Wyrzuce exception Counter";
    throw CounterKeyError();
}


void Team::SetPenaltyFlag(bool flag)
{
    this->penaltyFlag = flag;
}

void Team::SwitchPenaltyFlag()
{
    this->penaltyFlag = !(this->penaltyFlag);
}

bool Team::GetPenaltyFlag()
{
    return this->penaltyFlag;
}

void Team::SetTimeoutFlag(bool flag)
{
    this->timeoutFlag = flag;
}

void Team::SwitchTimeoutFlag()
{
    this->timeoutFlag = !(this->timeoutFlag);
}

bool Team::GetTimeoutFlag()
{
    return this->timeoutFlag;
}
