#ifndef MVC_H
#define MVC_H

#include "World.h"

enum Command { MoveLeft, MoveRight, Shoot };

class Controller 
{
private:
  std::unique_ptr<Logic::World> world;
public:
  void parseCommand(const Command& command);
};

#endif //MVC_H
