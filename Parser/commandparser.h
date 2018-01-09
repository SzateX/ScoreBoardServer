#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QString>
#include "Models/Classes/game.h"
#include "Parser/commandfactory.h"

/*!
 * \brief The CommandParser class. This class parse and execute commands and return all state of game ready to sent to clients.
 */
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
