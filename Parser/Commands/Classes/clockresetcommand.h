#ifndef CLOCKRESETCOMMAND_H
#define CLOCKRESETCOMMAND_H

#include <QString>
#include "Parser/Commands/Abstract/acommand.h"

class ClockResetCommand : public ACommand
{
    QString clock;
public:
    ClockResetCommand(QString clock);

    // ACommand interface
public:
    void Execute(AGame& gameObj) override;
};

#endif // CLOCKRESETCOMMAND_H
