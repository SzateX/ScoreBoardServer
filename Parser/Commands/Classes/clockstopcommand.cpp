#include "clockstopcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/areversetimer.h"

ClockStopCommand::ClockStopCommand(QString clock)
{
    this->clock = clock;
}

void ClockStopCommand::Execute(AGame &gameObj)
{
    AReverseTimer& timer = gameObj.GetClock(this->clock);
    //TODO
}
