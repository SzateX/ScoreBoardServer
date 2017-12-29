#include "pointssetcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"
#include "Models/Abstracts/acounter.h"

PointsSetCommand::PointsSetCommand(QString counter, QString team, unsigned int arg)
{
    this->counter = counter;
    this->team = team;
    this->arg = arg;
}

void PointsSetCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    ACounter& points = team.GetCounter(this->counter);
    points.SetPoints(this->arg);
}
