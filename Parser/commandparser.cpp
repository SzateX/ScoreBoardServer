#include "commandparser.h"
#include "rapidjson/document.h"
#include "Commands/Abstract/acommand.h"
#include "Models/Abstracts/ateam.h"
#include "Models/Abstracts/areversetimer.h"
#include <QDebug>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Exceptions/nojsonerror.h"
CommandParser::CommandParser()
{

}

void CommandParser::Parse(QString txt)
{
    rapidjson::Document d;
    if(d.Parse(txt.toStdString().c_str()).HasParseError())
    {
        qDebug() << "Nope is not json";
        throw NoJsonError();
    }
    qDebug() << "Jestem w Parserze";
    commandFactory.GetCommand(d)->Execute(game);
}

QString CommandParser::GetGameState()
{
    rapidjson::Document e;
    rapidjson::Document::AllocatorType& allocatore = e.GetAllocator();
    e.SetObject();
    rapidjson::Document d;
    rapidjson::Document::AllocatorType& allocator = d.GetAllocator();
    d.SetObject();
    rapidjson::Value home_name;
    rapidjson::Value away_name;
    home_name.SetString(game.GetTeam("home").GetName().toStdString().c_str(), game.GetTeam("home").GetName().length());
    away_name.SetString(game.GetTeam("away").GetName().toStdString().c_str(), game.GetTeam("away").GetName().length());
    d.AddMember("home_name", home_name, allocator);
    d.AddMember("home_points", game.GetTeam("home").GetCounter("primary").GetPoints(), allocator);
    d.AddMember("home_set_points", game.GetTeam("home").GetCounter("secondary").GetPoints(), allocator);
    d.AddMember("home_penalty", game.GetTeam("home").GetPenaltyFlag(), allocator);
    d.AddMember("home_timeout", game.GetTeam("home").GetTimeoutFlag(), allocator);
    d.AddMember("away_name", away_name, allocator);
    d.AddMember("away_points", game.GetTeam("away").GetCounter("primary").GetPoints(), allocator);
    d.AddMember("away_set_points", game.GetTeam("away").GetCounter("secondary").GetPoints(), allocator);
    d.AddMember("away_penalty", game.GetTeam("away").GetPenaltyFlag(), allocator);
    d.AddMember("away_timeout", game.GetTeam("away").GetTimeoutFlag(), allocator);
    d.AddMember("match_seconds", game.GetClock("primary").GetRemainingSeconds(), allocator);
    d.AddMember("match_twenty_four_seconds", game.GetClock("secondary").GetRemainingSeconds(), allocator);
    d.AddMember("match_period", game.GetPeriodCounter().GetPoints(), allocator);
    e.AddMember("data", d, allocatore);
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    e.Accept(writer);

    QString str(strbuf.GetString());
    return str;
}
