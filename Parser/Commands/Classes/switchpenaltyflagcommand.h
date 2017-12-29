#ifndef SWITCHPENALTYFLAGCOMMAND_H
#define SWITCHPENALTYFLAGCOMMAND_H

#include <QString>
#include "Parser/Commands/Abstract/acommand.h"

class SwitchPenaltyFlagCommand : public ACommand
{
    QString team;
public:
    SwitchPenaltyFlagCommand(QString team);

    // ACommand interface
public:
    void Execute(AGame &gameObj) override;
};

#endif // SWITCHPENALTYFLAGCOMMAND_H
