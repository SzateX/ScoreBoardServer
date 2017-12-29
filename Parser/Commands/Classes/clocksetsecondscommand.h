#ifndef CLOCKSETSECONDSCOMMAND_H
#define CLOCKSETSECONDSCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"
#include <QString>

class ClockSetSecondsCommand: public ACommand
{
    QString clock;
    int arg;
public:
    ClockSetSecondsCommand(QString clock, int arg);
    void Execute(AGame& gameObj) override;
};

#endif // CLOCKSETSECONDSCOMMAND_H
