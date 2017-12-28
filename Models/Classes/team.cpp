#include "team.h"

Team::Team(QString teamName)
{
    this->name = teamName;
    timeoutFlag = false;
    penaltyFlag = false;
    counters.insert("primary", Counter(0));
    counters.insert("secondary", Counter(0));
    counters.insert("tertiary", Counter(0));
}


void Team::SetName(const QString &name)
{
    this->name = name;
}

QString Team::GetName()
{
    return this->name;
}

ACounter &Team::GetCounter(const QString &key)
{
    if(counters.contains(key))
        return counters[key];
    throw CounterKeyError();
}
