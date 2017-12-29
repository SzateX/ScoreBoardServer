#include "pointsresetcommand.h"
#include "Models/Abstracts/agame.h"
#include "Models/Abstracts/ateam.h"
#include "Models/Abstracts/acounter.h"

PointsResetCommand::PointsResetCommand(QString counter, QString team)
{
    this->counter = counter;
    this->team = team;
}

void PointsResetCommand::Execute(AGame &gameObj)
{
    ATeam& team = gameObj.GetTeam(this->team);
    ACounter& points = team.GetCounter(this->counter);
    points.SetPoints();
}
