#include "timer.h"

Timer::Timer()
{
    this->secondsFromLastAction = 0;
    this->isEnabled = false;
    this->timestamp = QDateTime::currentDateTimeUtc();
}


void Timer::Start()
{
    if(!this->isEnabled)
    {
        this->isEnabled = true;
        this->timestamp = QDateTime::currentDateTimeUtc();
    }
}

void Timer::End()
{
    if(this->isEnabled)
    {
        isEnabled = false;
        this->secondsFromLastAction += timestamp.msecsTo(QDateTime::currentDateTimeUtc()) / 1000.0;
    }
}

void Timer::ResetTimer()
{
    this->secondsFromLastAction = 0.0;
    this->timestamp = QDateTime::currentDateTimeUtc();
}

double Timer::GetSeconds()
{
    if(isEnabled)
        return this->secondsFromLastAction + timestamp.msecsTo(QDateTime::currentDateTime()) / 1000.0;
    return this->secondsFromLastAction;
}
