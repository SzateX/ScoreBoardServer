#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QMap>
#include <memory>
#include <unordered_map>
#include "Models/Abstracts/ateam.h"

class Counter;
class ACounter;

class Team : public ATeam
{
    QString name;
    QMap<QString, std::unique_ptr<Counter>> counters;
public:
    bool timeoutFlag;
    bool penaltyFlag;
    Team(QString teamName = "noName");

    // ATeam interface
public:
    void SetName(const QString &name) override;
    QString GetName() override;
    ACounter &GetCounter(const QString &key) override;
};

#endif // TEAM_H
