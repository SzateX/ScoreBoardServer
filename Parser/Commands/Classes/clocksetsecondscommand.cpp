#include "clocksetsecondscommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/areversetimer.h"

ClockSetSecondsCommand::ClockSetSecondsCommand(QString clock, int arg)
{
    this->clock = clock;
    this->arg = arg;
}

void ClockSetSecondsCommand::Execute(AGame &gameObj)
{
    AReverseTimer& timer = gameObj.GetClock(this->clock);
    timer.SetMaxSeconds(this->arg);
}
