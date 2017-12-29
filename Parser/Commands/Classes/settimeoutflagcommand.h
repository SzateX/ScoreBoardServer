#ifndef SETTIMEOUTFLAGCOMMAND_H
#define SETTIMEOUTFLAGCOMMAND_H

#include <QString>
#include "Parser/Commands/Abstract/acommand.h"

class SetTimeoutFlagCommand : public ACommand
{
    QString team;
    bool arg;
public:
    SetTimeoutFlagCommand(QString team, bool arg);

    // ACommand interface
public:
    void Execute(AGame &gameObj) override;
};

#endif // SETTIMEOUTFLAGCOMMAND_H
