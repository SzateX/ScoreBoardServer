#ifndef CLOCKSTOPCOMMAND_H
#define CLOCKSTOPCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"
#include <QString>

class ClockStopCommand: public ACommand
{
    QString clock;
public:
    ClockStopCommand(QString clock);
    void Execute(AGame& gameObj) override;
};

#endif // CLOCKSTOPCOMMAND_H
