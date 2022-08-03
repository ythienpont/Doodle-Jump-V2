#ifndef WORLD_H
#define WORLD_H

#include "Player.h"
#include "Platform.h"
#include <memory>

namespace Logic
{
  class World 
  {
    std::unique_ptr<Player> player;
    std::unique_ptr<Platform> platform;
    void checkPlayerCollisions();
    void checkProjectileCollisions();
  public:
    World();
    void update();
    void movePlayerLeft();
    void movePlayerRight();
    void playerShoot();
  };
}
#endif //WORLD_H
