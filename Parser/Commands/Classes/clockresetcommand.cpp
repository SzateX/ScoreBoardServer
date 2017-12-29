#include "clockresetcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/areversetimer.h"


ClockResetCommand::ClockResetCommand(QString clock)
{
    this->clock = clock;
}


void ClockResetCommand::Execute(AGame& gameObj)
{
    AReverseTimer& timer = gameObj.GetClock(this->clock);
    timer.ResetClock();
}
