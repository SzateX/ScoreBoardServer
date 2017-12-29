#include "pointsaddcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"
#include "Models/Abstracts/acounter.h"


PointsAddCommand::PointsAddCommand(QString counter, QString team, unsigned int arg)
{
    this->counter = counter;
    this->team = team;
    this->arg = arg;
}

void PointsAddCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    ACounter& points = team.GetCounter(this->counter);
    points.AddPoint(this->arg);
}
