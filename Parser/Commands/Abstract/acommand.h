#ifndef ACOMMAND_H
#define ACOMMAND_H

class AGame;

class ACommand
{
public:
    ACommand();
    virtual void Execute(AGame& gameObj) = 0;
    virtual ~ACommand();
};

#endif // ACOMMAND_H
