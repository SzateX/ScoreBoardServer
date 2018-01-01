#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Parser/acommandfactory.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <memory>
#include <map>
#include <functional>
class ACommand;

class CommandFactory : public ACommandFactory
{
public:
    CommandFactory();

    // ACommandFactory interface
public:
    std::unique_ptr<ACommand>GetCommand(QJsonDocument &json) override;

private:
    std::map<QString, std::function<std::unique_ptr<ACommand>(QJsonObject&)>> commandMap;
    static std::unique_ptr<ACommand> ParseAndGetClockReset(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetClockSet(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetClockStart(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetClockStop(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPeriodSet(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsAdd(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsReset(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsSet(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsSubtract(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSetName(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSetPenalty(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSetTimeout(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSwitchPenalty(QJsonObject &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSwitchTimeout(QJsonObject &jsonObj);

};

#endif // COMMANDFACTORY_H
