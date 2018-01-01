#ifndef ATEAM_H
#define ATEAM_H

#include <QString>
#include <memory>
#include "Models/Abstracts/acounter.h"

class ATeam
{
public:
    ATeam();
    virtual void SetName(const QString& name) = 0;
    virtual QString GetName() = 0;
    virtual void SetPenaltyFlag(bool flag) = 0;
    virtual void SwitchPenaltyFlag() = 0;
    virtual bool GetPenaltyFlag() = 0;
    virtual void SetTimeoutFlag(bool flag) = 0;
    virtual void SwitchTimeoutFlag() = 0;
    virtual bool GetTimeoutFlag() = 0;
    virtual ACounter& GetCounter(const QString& key) = 0;
    virtual ~ATeam();
};

#endif // ATEAM_H
