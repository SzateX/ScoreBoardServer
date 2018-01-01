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


std::unique_ptr<ACommand> CommandFactory::GetCommand(QJsonDocument &json)
{
    QJsonObject jsonObj = json.object();
    if(jsonObj.isEmpty())
        throw 0;
    if(!jsonObj.contains("cmd"))
        throw 0;
    QString cmd = jsonObj["cmd"].toString();
    if(commandMap.count(cmd))
        return commandMap[cmd](jsonObj);
    throw 0;
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockReset(QJsonObject &jsonObj)
{
    if(!jsonObj.contains("clock"))
        throw 0;
    if(!jsonObj["clock"].isString())
        throw 0;
    QString clock = jsonObj["clock"].toString();
    return std::make_unique<ClockResetCommand, QString>(clock);
}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockSet(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockStart(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetClockStop(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPeriodSet(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsAdd(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsReset(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsSet(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetPointsSubtract(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSetName(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSetPenalty(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSetTimeout(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSwitchPenalty(QJsonObject &jsonObj)
{

}

std::unique_ptr<ACommand> CommandFactory::ParseAndGetSwitchTimeout(QJsonObject &jsonObj)
{

}
