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
    virtual ACounter& GetCounter(const QString& key) = 0;
};

#endif // ATEAM_H
