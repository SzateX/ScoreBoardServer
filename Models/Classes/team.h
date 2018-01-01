#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QMap>
#include <memory>
#include <map>
#include "Models/Abstracts/ateam.h"

class Counter;
class ACounter;

class Team : public ATeam
{
    QString name;
    std::map<QString, std::unique_ptr<Counter>> counters;
    bool timeoutFlag;
    bool penaltyFlag;
public:
    Team(QString teamName = "noName");

    // ATeam interface
public:
    void SetName(const QString &name) override;
    QString GetName() override;
    ACounter &GetCounter(const QString &key) override;
    void SetPenaltyFlag(bool flag) override;
    void SwitchPenaltyFlag() override;
    bool GetPenaltyFlag() override;
    void SetTimeoutFlag(bool flag) override;
    void SwitchTimeoutFlag() override;
    bool GetTimeoutFlag() override;
};

#endif // TEAM_H
