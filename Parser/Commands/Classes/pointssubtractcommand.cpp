#include "pointssubtractcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"
#include "Models/Abstracts/acounter.h"

PointsSubtractCommand::PointsSubtractCommand(QString counter, QString team, unsigned int arg)
{
    this->counter = counter;
    this->team = team;
    this->arg = arg;
}

void PointsSubtractCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    ACounter& points = team.GetCounter(this->counter);
    points.SubtractPoint(this->arg);
}
