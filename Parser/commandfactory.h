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

/*!
 * \brief The CommandFactory class. Implements ACommandFactory interface
 */
class CommandFactory : public ACommandFactory
{
public:
    /*!
     * \brief CommandFactory constructor
     */
    CommandFactory();

    // ACommandFactory interface
public:
    /*!
     * \brief GetCommand gets command object needed for execution
     * \param json json document which contains serilized data of command
     * \return pointer to ACommand class object containing command ready to execute
     */
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
    static std::unique_ptr<ACommand> ParseAndGetPing(rapidjson::Document &jsonObj);
};

#endif // COMMANDFACTORY_H
