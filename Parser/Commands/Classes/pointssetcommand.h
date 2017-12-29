#ifndef POINTSSETCOMMAND_H
#define POINTSSETCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"
#include <QString>

class PointsSetCommand: public ACommand
{
    QString counter;
    QString team;
    unsigned int arg;
public:
    PointsSetCommand(QString counter, QString team, unsigned int arg);
    void Execute(AGame& gameObj) override;
};

#endif // POINTSSETCOMMAND_H
