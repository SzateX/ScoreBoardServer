#include "setpenaltyflagcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"

SetPenaltyFlagCommand::SetPenaltyFlagCommand(QString team, bool arg)
{
    this->team = team;
    this->arg = arg;
}

void SetPenaltyFlagCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    //TODO
}
