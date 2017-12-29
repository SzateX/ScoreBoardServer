#ifndef PERIODSETCOMMAND_H
#define PERIODSETCOMMAND_H

#include "Parser/Commands/Abstract/acommand.h"

class PeriodSetCommand: public ACommand
{
    unsigned int arg;
public:
    PeriodSetCommand(unsigned int arg);
    void Execute(AGame& gameObj) override;
};

#endif // PERIODSETCOMMAND_H
