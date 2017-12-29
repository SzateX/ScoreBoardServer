#include "periodsetcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/acounter.h"

PeriodSetCommand::PeriodSetCommand(unsigned int arg)
{
    this->arg = arg;
}

void PeriodSetCommand::Execute(AGame &gameObj)
{
    ACounter& period = gameObj.GetPeriodCounter();
    period.SetPoints(this->arg);
}
