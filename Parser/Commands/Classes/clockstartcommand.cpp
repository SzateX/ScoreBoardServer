#include "clockstartcommand.h"
#include "Models/Abstracts/areversetimer.h"
#include "Models/Abstracts/agame.h"

ClockStartCommand::ClockStartCommand(QString clock)
{
    this->clock = clock;
}

void ClockStartCommand::Execute(AGame &gameObj)
{
    AReverseTimer& timer = gameObj.GetClock(this->clock);
    //TODO
}
