#ifndef ACOMMANDFACTORY_H
#define ACOMMANDFACTORY_H

#include <QJsonDocument>

class ACommand;

class ACommandFactory
{
public:
    ACommandFactory();
    virtual ACommand& GetCommand(QJsonDocument& json) = 0;
    virtual ~ACommandFactory();
};

#endif // ACOMMANDFACTORY_H
