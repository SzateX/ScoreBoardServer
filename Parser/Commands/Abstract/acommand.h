#ifndef ACOMMAND_H
#define ACOMMAND_H

class AGame;

/*!
 * \brief The ACommand class is an interface for any commands classes
 */
class ACommand
{
public:
    ACommand();
    virtual void Execute(AGame& gameObj) = 0;
    virtual ~ACommand();
};

#endif // ACOMMAND_H
