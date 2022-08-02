#ifndef MVC_H
#define MVC_H

#include <SFML/Graphics.hpp>
#include "World.h"

enum Command { MoveLeft, MoveRight, Shoot };

class Controller 
{
private:
  std::unique_ptr<World> world;
public:
  void parseCommand(const Command& command);
};

class View
{

};

#endif //MVC_H
