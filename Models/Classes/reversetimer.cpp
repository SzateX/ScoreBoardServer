#include "reversetimer.h"
#include <QDebug>
void ReverseTimer::ResetState()
{
    End();
    ResetTimer();
}

ReverseTimer::ReverseTimer(double seconds)
{
    this->maxSeconds = seconds;
    QObject::connect(&(this->deffer), &QTimer::timeout, [=](){this->End();});
}


void ReverseTimer::ResetClock()
{
    ResetState();
    Start();
}

double ReverseTimer::GetRemainingSeconds()
{
    return maxSeconds - Timer::GetSeconds();
}

void ReverseTimer::SetMaxSeconds(double seconds)
{
    ResetState();
    this->maxSeconds = seconds;
}


void ReverseTimer::Start()
{
    double delta = this->maxSeconds - Timer::GetSeconds();
    qDebug() << "Delta: " << delta;
    deffer.start(delta*1000);
    Timer::Start();
}

void ReverseTimer::End()
{
    Timer::End();
    if(deffer.isActive())
        deffer.stop();
}
