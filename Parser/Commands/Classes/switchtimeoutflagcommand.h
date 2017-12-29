#ifndef SWITCHTIMEOUTFLAGCOMMAND_H
#define SWITCHTIMEOUTFLAGCOMMAND_H

#include <QString>
#include "Parser/Commands/Abstract/acommand.h"

class SwitchTimeoutFlagCommand : public ACommand
{
    QString team;
public:
    SwitchTimeoutFlagCommand(QString team);


    // ACommand interface
public:
    void Execute(AGame &gameObj) override;
};

#endif // SWITCHTIMEOUTFLAGCOMMAND_H
