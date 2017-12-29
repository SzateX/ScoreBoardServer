#include "switchpenaltyflagcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"

SwitchPenaltyFlagCommand::SwitchPenaltyFlagCommand(QString team)
{
    this->team = team;
}

void SwitchPenaltyFlagCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    //TODO
}
