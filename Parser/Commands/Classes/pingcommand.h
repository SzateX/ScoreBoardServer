#ifndef PINGCOMMAND_H
#define PINGCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"

class PingCommand : public ACommand
{
public:
    PingCommand();

    // ACommand interface
public:
    void Execute(AGame &gameObj) override;
};

#endif // PINGCOMMAND_H
