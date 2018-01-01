#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "Parser/acommandfactory.h"
#include <QJsonDocument>
#include <QJsonObject>

class ACommand;

class CommandFactory : public ACommandFactory
{
public:
    CommandFactory();

    // ACommandFactory interface
public:
    ACommand &GetCommand(QJsonDocument &json) override;

private:
    ACommand &ParseAndGetClockReset(QJsonObject &jsonObj);
    ACommand &ParseAndGetClockSet(QJsonObject &jsonObj);
    ACommand &ParseAndGetClockStart(QJsonObject &jsonObj);
    ACommand &ParseAndGetClockStop(QJsonObject &jsonObj);
    ACommand &ParseAndGetPeriodSet(QJsonObject &jsonObj);
    ACommand &ParseAndGetPointsAdd(QJsonObject &jsonObj);
    ACommand &ParseAndGetPointsReset(QJsonObject &jsonObj);
    ACommand &ParseAndGetPointsSet(QJsonObject &jsonObj);
    ACommand &ParseAndGetPointsSubtract(QJsonObject &jsonObj);
    ACommand &ParseAndGetSetName(QJsonObject &jsonObj);
    ACommand &ParseAndGetSetPenalty(QJsonObject &jsonObj);
    ACommand &ParseAndGetSetTimeout(QJsonObject &jsonObj);
    ACommand &ParseAndGetSwitchPenalty(QJsonObject &jsonObj);
    ACommand &ParseAndGetSwitchTimeout(QJsonObject &jsonObj);

};

#endif // COMMANDFACTORY_H
