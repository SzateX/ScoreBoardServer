#ifndef ACOMMANDFACTORY_H
#define ACOMMANDFACTORY_H

#include <QJsonDocument>
#include <memory>

class ACommand;

class ACommandFactory
{
public:
    ACommandFactory();
    virtual std::unique_ptr<ACommand> GetCommand(QJsonDocument& json) = 0;
    virtual ~ACommandFactory();
};

#endif // ACOMMANDFACTORY_H
