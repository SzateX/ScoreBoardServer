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
    std::unique_ptr<ACommand>GetCommand(rapidjson::Document& json) override;

private:
    std::map<QString, std::function<std::unique_ptr<ACommand>(rapidjson::Document&)>> commandMap;
    static std::unique_ptr<ACommand> ParseAndGetClockReset(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetClockSet(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetClockStart(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetClockStop(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPeriodSet(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsAdd(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsReset(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsSet(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetPointsSubtract(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSetName(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSetPenalty(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSetTimeout(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSwitchPenalty(rapidjson::Document &jsonObj);
    static std::unique_ptr<ACommand> ParseAndGetSwitchTimeout(rapidjson::Document &jsonObj);
    static QString GetSchemaString(QString &filename);
    static bool IsValidJson(QString& schemaString , rapidjson::Document &jsonObj);
};

#endif // COMMANDFACTORY_H
