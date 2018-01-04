#include "commandfactory.h"
#include "Parser/Commands/Classes/clockresetcommand.h"
#include "Parser/Commands/Classes/clocksetsecondscommand.h"
#include "Parser/Commands/Classes/clockstartcommand.h"
#include "Parser/Commands/Classes/clockstopcommand.h"
#include "Parser/Commands/Classes/periodsetcommand.h"
#include "Parser/Commands/Classes/pointsaddcommand.h"
#include "Parser/Commands/Classes/pointsresetcommand.h"
#include "Parser/Commands/Classes/pointssetcommand.h"
#include "Parser/Commands/Classes/pointssubtractcommand.h"
#include "Parser/Commands/Classes/setnamecommand.h"
#include "Parser/Commands/Classes/setpenaltyflagcommand.h"
#include "Parser/Commands/Classes/settimeoutflagcommand.h"
#include "Parser/Commands/Classes/switchpenaltyflagcommand.h"
#include "Parser/Commands/Classes/switchtimeoutflagcommand.h"
#include "rapidjson/document.h"
#include "rapidjson/schema.h"
#include "rapidjson/stringbuffer.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <functional>

CommandFactory::CommandFactory()
{
    commandMap["clock_reset"] = std::bind(&CommandFactory::ParseAndGetClockReset, std::placeholders::_1);
    commandMap["clock_set_seconds"] = std::bind(&CommandFactory::ParseAndGetClockSet, std::placeholders::_1);
    commandMap["clock_start"] = std::bind(&CommandFactory::ParseAndGetClockStart, std::placeholders::_1);
    commandMap["clock_stop"] = std::bind(&CommandFactory::ParseAndGetClockStop, std::placeholders::_1);
    commandMap["period_set"] = std::bind(&CommandFactory::ParseAndGetPeriodSet, std::placeholders::_1);
    commandMap["points_add"] = std::bind(&CommandFactory::ParseAndGetPointsAdd, std::placeholders::_1);
    commandMap["points_reset"] = std::bind(&CommandFactory::ParseAndGetPointsReset, std::placeholders::_1);
    commandMap["points_set"] = std::bind(&CommandFactory::ParseAndGetPointsSet, std::placeholders::_1);
    commandMap["points_subtract"] = std::bind(&CommandFactory::ParseAndGetPointsSubtract, std::placeholders::_1);
    commandMap["set_name"] = std::bind(&CommandFactory::ParseAndGetSetName, std::placeholders::_1);
    commandMap["set_penalty_flag"] = std::bind(&CommandFactory::ParseAndGetSetPenalty, std::placeholders::_1);
    commandMap["set_timeout_flag"] = std::bind(&CommandFactory::ParseAndGetSetTimeout, std::placeholders::_1);
    commandMap["switch_penalty_flag"] = std::bind(&CommandFactory::ParseAndGetSwitchPenalty, std::placeholders::_1);
    commandMap["switch_timeout_flag"] = std::bind(&CommandFactory::ParseAndGetSwitchTimeout, std::placeholders::_1);
}


std::unique_ptr<ACommand> CommandFactory::GetCommand(rapidjson::Document& json)
{
    assert(json.HasMember("cmd"));
    assert(json["cmd"].IsString());
    QString cmd = QString::fromStdString(json["cmd"].GetString());
    json.RemoveMember("cmd");
    return commandMap[cmd](json);
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockReset(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/ClockResetCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString clock = jsonObj["clock"].GetString();
        return std::make_unique<ClockResetCommand>(clock);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockSet(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/ClockSetSecondsCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString clock = jsonObj["clock"].GetString();
        int arg = jsonObj["arg"].GetInt();
        return std::make_unique<ClockSetSecondsCommand>(clock, arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockStart(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/ClockStartCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString clock = jsonObj["clock"].GetString();
        return std::make_unique<ClockStartCommand>(clock);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockStop(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/ClockStopCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString clock = jsonObj["clock"].GetString();
        return std::make_unique<ClockStopCommand>(clock);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPeriodSet(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/PeriodSetCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        int arg = jsonObj["arg"].GetInt();
        return std::make_unique<PeriodSetCommand>(arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsAdd(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/PointsAddCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString counter = jsonObj["counter"].GetString();
        QString team = jsonObj["team"].GetString();
        int arg = jsonObj["arg"].GetInt();
        return std::make_unique<PointsAddCommand>(counter, team, arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsReset(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/PointsResetCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString counter = jsonObj["counter"].GetString();
        QString team = jsonObj["team"].GetString();
        return std::make_unique<PointsResetCommand>(counter, team);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsSet(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/PointsSetCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString counter = jsonObj["counter"].GetString();
        QString team = jsonObj["team"].GetString();
        int arg = jsonObj["arg"].GetInt();
        return std::make_unique<PointsSetCommand>(counter, team, arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsSubtract(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/PointsSubtractCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString counter = jsonObj["counter"].GetString();
        QString team = jsonObj["team"].GetString();
        int arg = jsonObj["arg"].GetInt();
        return std::make_unique<PointsSubtractCommand>(counter, team, arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSetName(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/SetNameCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString team = jsonObj["team"].GetString();
        QString arg = jsonObj["arg"].GetString();
        return std::make_unique<SetNameCommand>(team, arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSetPenalty(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/SetPenaltyCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString team = jsonObj["team"].GetString();
        bool arg = jsonObj["arg"].GetBool();
        return std::make_unique<SetPenaltyFlagCommand>(team, arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSetTimeout(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/SetTimeoutCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString team = jsonObj["team"].GetString();
        bool arg = jsonObj["arg"].GetBool();
        return std::make_unique<SetTimeoutFlagCommand>(team, arg);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSwitchPenalty(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/SwitchPenaltyCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString team = jsonObj["team"].GetString();
        return std::make_unique<SwitchPenaltyFlagCommand>(team);
    }
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSwitchTimeout(rapidjson::Document &jsonObj)
{
    QString path = ":/Json/SwitchTimeoutCommandSchema.json";
    QString schemaString = CommandFactory::GetSchemaString(path);
    bool isValid = CommandFactory::IsValidJson(schemaString, jsonObj);
    if(isValid)
    {
        QString team = jsonObj["team"].GetString();
        return std::make_unique<SwitchTimeoutFlagCommand>(team);
    }
    throw 0;
}

QString CommandFactory::GetSchemaString(QString &filename)
{
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) throw 0;
    QTextStream in(&f);
    QString schema = in.readAll();
    return schema;
}

bool CommandFactory::IsValidJson(QString &schemaString, rapidjson::Document &jsonObj)
{
    rapidjson::Document sd;
    sd.Parse(schemaString.toStdString().c_str());
    rapidjson::SchemaDocument schema(sd);
    rapidjson::SchemaValidator validator(schema);

    if (!jsonObj.Accept(validator)) {
        // Input JSON is invalid according to the schema
        // Output diagnostic information
        rapidjson::StringBuffer sb;
        validator.GetInvalidSchemaPointer().StringifyUriFragment(sb);
        qDebug() << "Invalid schema: \n";
        qDebug() << sb.GetString();
        qDebug() << "Invalid keyword: \n";
        qDebug() << validator.GetInvalidSchemaKeyword();
        sb.Clear();
        validator.GetInvalidDocumentPointer().StringifyUriFragment(sb);
        qDebug() << "Invalid document: \n";
        qDebug() << sb.GetString();
        return false;
    }
    return true;
}
