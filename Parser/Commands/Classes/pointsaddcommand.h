#ifndef POINTSADDCOMMAND_H
#define POINTSADDCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"
#include <QString>

class PointsAddCommand: public ACommand
{
    QString counter;
    QString team;
    unsigned int arg;
public:
    PointsAddCommand(QString counter, QString team, unsigned int arg);
    void Execute(AGame& gameObj) override;
};

#endif // POINTSADDCOMMAND_H
