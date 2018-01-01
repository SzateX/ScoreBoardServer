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
    auto g = std::bind(&CommandFactory::ParseAndGetClockReset, this, std::placeholders::_1);
}


ACommand &CommandFactory::GetCommand(QJsonDocument &json)
{
    QJsonObject jsonObj = json.object();
    if(jsonObj.isEmpty())
        throw 0;
    if(!jsonObj.contains("cmd"))
        throw 0;
    QString cmd = jsonObj["cmd"].toString();
    /*switch(cmd)
    {
        case "clock_reset":
            return ParseAndGetClockReset(jsonObj);
        case "clock_set_seconds":
            return ParseAndGetClockSet(jsonObj);
        case "clock_start":
            return ParseAndGetClockStart(jsonObj);
        case "clock_stop":
            return ParseAndGetClockStop(jsonObj);
        case "period_set":
            return ParseAndGetPeriodSet(jsonObj);
        case "points_add":
            return ParseAndGetPointsAdd(jsonObj);
        case "points_reset":
            return ParseAndGetPointsReset(jsonObj);
        case "points_set":
            return ParseAndGetPointsSet(jsonObj);
        case "points_subtract":
            return ParseAndGetPointsSubtract(jsonObj);
        case "set_name":
            return ParseAndGetSetName(jsonObj);
        case "set_penalty_flag":
            return ParseAndGetSetPenalty(jsonObj);
        case "set_timeout_flag":
            return ParseAndGetSetTimeout(jsonObj);
        case "switch_penalty_flag":
            return ParseAndGetSwitchPenalty(jsonObj);
        case "switch_timeout_flag":
            return ParseAndGetSwitchTimeout(jsonObj);
        default:
            //throw new ParseError("There is no command: " + cmd);
            throw 0;
    }*/
}

ACommand &CommandFactory::ParseAndGetClockReset(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetClockSet(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetClockStart(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetClockStop(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetPeriodSet(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetPointsAdd(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetPointsReset(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetPointsSet(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetPointsSubtract(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetSetName(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetSetPenalty(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetSetTimeout(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetSwitchPenalty(QJsonObject &jsonObj)
{

}

ACommand &CommandFactory::ParseAndGetSwitchTimeout(QJsonObject &jsonObj)
{

}
