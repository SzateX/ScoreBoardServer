#ifndef CLOCKSTARTCOMMAND_H
#define CLOCKSTARTCOMMAND_H


#include "Parser/Commands/Abstract/acommand.h"
#include <QString>

class ClockStartCommand: public ACommand
{
    QString clock;
public:
    ClockStartCommand(QString clock);
    void Execute(AGame& gameObj) override;
};

#endif // CLOCKSTARTCOMMAND_H
