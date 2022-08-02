#include "MVC.h"

void Controller::parseCommand(const Command& command)
{
  switch(command)
  {
    case MoveLeft:
      world->movePlayerLeft();
      break;
    case MoveRight:
      world->movePlayerRight();
      break;
    case Shoot:
      world->playerShoot();
      break;
  }
  world->update();
}
