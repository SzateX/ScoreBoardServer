#include "switchtimeoutflagcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"


SwitchTimeoutFlagCommand::SwitchTimeoutFlagCommand(QString team)
{
    this->team = team;
}

void SwitchTimeoutFlagCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    team.SwitchTimeoutFlag();
}
