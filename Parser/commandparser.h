#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QString>
#include "Models/Classes/game.h"
#include "Parser/commandfactory.h"
class CommandParser
{
    Game game;
    CommandFactory commandFactory;
public:
    CommandParser();
    void Parse(QString txt);
    QString GetGameState();
};

#endif // COMMANDPARSER_H
