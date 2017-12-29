#include "setnamecommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"

SetNameCommand::SetNameCommand(QString team, QString arg)
{
    this->team = team;
    this->arg = arg;
}

void SetNameCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    team.SetName(this->arg);
}
