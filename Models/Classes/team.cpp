#include "team.h"
#include "Exceptions/counterkeyerror.h"
#include "Models/Abstracts/acounter.h"
#include "Models/Classes/counter.h"

Team::Team(QString teamName)
{
    this->name = teamName;
    timeoutFlag = false;
    penaltyFlag = false;
    counters.insert("primary", std::make_unique<Counter>(0));
    counters.insert("secondary", std::make_unique<Counter>(0));
    counters.insert("tertiary", std::make_unique<Counter>(0));
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
    if(counters.contains(key))
        return *counters[key];
    throw CounterKeyError();
}
