#ifndef SETNAMECOMMAND_H
#define SETNAMECOMMAND_H

#include <QString>
#include "Parser/Commands/Abstract/acommand.h"

class SetNameCommand : public ACommand
{
    QString team;
    QString arg;
public:
    SetNameCommand(QString team, QString arg);

    // ACommand interface
public:
    void Execute(AGame &gameObj) override;
};

#endif // SETNAMECOMMAND_H
