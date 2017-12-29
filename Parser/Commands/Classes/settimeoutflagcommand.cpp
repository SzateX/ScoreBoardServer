#include "settimeoutflagcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"

SetTimeoutFlagCommand::SetTimeoutFlagCommand(QString team, bool arg)
{
    this->team = team;
    this->arg = arg;
}

void SetTimeoutFlagCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    //TODO
}
