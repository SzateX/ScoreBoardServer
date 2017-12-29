#ifndef POINTSSUBTRACTCOMMAND_H
#define POINTSSUBTRACTCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"
#include <QString>

class PointsSubtractCommand: public ACommand
{
    QString counter;
    QString team;
    unsigned int arg;
public:
    PointsSubtractCommand(QString counter, QString team, unsigned int arg);
    void Execute(AGame& gameObj) override;
};

#endif // POINTSSUBTRACTCOMMAND_H
