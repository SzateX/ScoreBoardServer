#ifndef POINTSRESETCOMMAND_H
#define POINTSRESETCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"
#include <QString>

class PointsResetCommand: public ACommand
{
    QString counter;
    QString team;
public:
    PointsResetCommand(QString counter, QString team);
    void Execute(AGame& gameObj) override;
};

#endif // POINTSRESETCOMMAND_H
