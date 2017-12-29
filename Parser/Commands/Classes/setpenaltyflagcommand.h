#ifndef SETPENALTYFLAGCOMMAND_H
#define SETPENALTYFLAGCOMMAND_H

#include <QString>
#include "Parser/Commands/Abstract/acommand.h"

class SetPenaltyFlagCommand : public ACommand
{
    QString team;
    bool arg;
public:
    SetPenaltyFlagCommand(QString team, bool arg);

    // ACommand interface
public:
    void Execute(AGame &gameObj) override;
};

#endif // SETPENALTYFLAGCOMMAND_H
