#ifndef ACOMMANDFACTORY_H
#define ACOMMANDFACTORY_H

#include <QJsonDocument>
#include <memory>
#include "rapidjson/document.h"

class ACommand;

/*!
 * \brief The ACommandFactory class is an interface for CommandFactory
 */
class ACommandFactory
{
public:
    ACommandFactory();
    virtual std::unique_ptr<ACommand> GetCommand(rapidjson::Document& json) = 0;
    virtual ~ACommandFactory();
};

#endif // ACOMMANDFACTORY_H
