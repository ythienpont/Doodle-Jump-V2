#include "World.h"
#include <iostream>

World::World()
{
  player = std::make_unique<Player>(Vec2D(240,50));
  platform = std::make_unique<Platform>(Vec2D(220, 10));
}

void World::checkPlayerCollisions()
{
  // Loop over enemies, doesn't matter if going down
  if (player->goingDown())
  {
    // Loop over all platforms and bonuses
    if (player->collidesWith(*platform))
    {
      player->jump();
    }
  }
}

void World::checkProjectileCollisions()
{
  // Loop over all projectiles
}

void World::update()
{
  checkPlayerCollisions();
  checkProjectileCollisions();
  player->update();

  // Update all moving platforms
}

void movePlayerLeft()
{
  std::cout << "LEFT\n";
}

void movePlayerRight()
{
  std::cout << "RIGHT\n";
}

void playerShoot()
{
  std::cout << "SHOOT\n";
}
