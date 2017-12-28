#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QMap>
#include "Exceptions/counterkeyerror.h"
#include "Models/Abstracts/ateam.h"
#include "Models/Abstracts/acounter.h"
#include "Models/Classes/counter.h"

class Team : public ATeam
{
    QString name;
    QMap<QString, Counter> counters;
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
