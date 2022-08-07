#include "World.h"
#include <iostream>

Logic::World::World(std::shared_ptr<AbstractFactory> factory) : difficulty(STARTINGDIFF)
{
  player = factory->createPlayer(Vec2D(240,100));
  //player = factory->createPlayer(Vec2D(120,100));
  platforms.push_back(factory->createPlatform(Vec2D(240,60)));
}

void Logic::World::checkPlayerCollisions()
{
  // Loop over enemies, doesn't matter if going down
  if (player->goingDown())
  {
    // Loop over all platforms and bonuses

    for (auto& bonus : bonuses)
    {
      if (player->collidesWith(*bonus))
      {
        // Add bonus
      }
    }
    for (auto& platform : platforms)
    {
      if (player->collidesWith(*platform))
      {
        player->jump();
        platform->jumpOn();
      }
    }
  }
}

Vec2D Logic::World::getHighestPlatformPosition() const
{
  Vec2D highest(0,0);

  for (auto& platform : platforms)
  {
    if (platform->getPosition().y > highest.y) highest = platform->getPosition();  
  }

  return highest;
}

int Logic::World::getTotalCredits() const
{
  int totalCredits = 0;

  for (auto& platform : platforms)
    totalCredits += platform->getCredits();

  return totalCredits;
}

void Logic::World::spawnEntities(std::shared_ptr<AbstractFactory> factory)
{
  spawnPlatforms(factory); 
  spawnEnemies(factory);

  if (player->isShooting())
  {
    spawnPlayerBullet(factory);
    player->reset();
  }
}

void Logic::World::spawnPlayerBullet(std::shared_ptr<AbstractFactory> factory)
{
  projectiles.push_back(factory->createPlayerBullet(player->getPosition()));
}

void Logic::World::spawnEnemies(std::shared_ptr<AbstractFactory> factory)
{

}

void Logic::World::spawnBonuses(std::shared_ptr<AbstractFactory> factory)
{

}

void Logic::World::spawnPlatform(std::shared_ptr<AbstractFactory> factory, const Vec2D& pos, const int platformType)
{
    switch (platformType)
    {
      case 0:
        platforms.push_back(factory->createHPlatform(pos));
        break;
      case 1:
        platforms.push_back(factory->createVPlatform(pos));
        break;
      case 2:
        platforms.push_back(factory->createTempPlatform(pos));
        break;
      default:
        platforms.push_back(factory->createPlatform(pos)); 
        break;
    }
}

void Logic::World::spawnPlatforms(std::shared_ptr<AbstractFactory> factory)
{
  while (!Camera::getInstance()->isOutOfUpperBounds(getHighestPlatformPosition()))
  {
    int platformType = Random::getInstance()->getValue() % difficulty;
    Vec2D randomPos(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH),
        getHighestPlatformPosition().y+PLATFORM_OFFSET);

    spawnPlatform(factory, randomPos, platformType);
  }

  /*
  // Could be optimized, but the length of the platform array will never be large enough to comprimise on readability
  while (getTotalCredits() < difficulty - 3)
  {
    int platformType = Random::getInstance()->getValue() % (difficulty/2);
    Vec2D randomPos(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH),
        player->getPosition().y+SCREENH+(Random::getInstance()->getValue() % 180));
  
    spawnPlatform(factory, randomPos, platformType);
  }
  */
}


std::vector<std::shared_ptr<Representation::View> > Logic::World::getSprites() const
{
  std::vector<std::shared_ptr<Representation::View> > sprites;
  
  for (auto& platform : platforms)
    sprites.push_back(platform->view);

  for (auto& bonus : bonuses)
    sprites.push_back(bonus->view);

  for (auto& enemy : enemies)
    sprites.push_back(enemy->view);

  for (auto& tile : tiles)
    sprites.push_back(tile->view);

  for (auto& projectile : projectiles)
    sprites.push_back(projectile->view);

  sprites.push_back(player->view);

  return sprites;
}

void Logic::World::checkProjectileCollisions()
{
  for (auto& projectile : projectiles)
  {
    if (projectile->isFriendly())
    {
      for (auto& enemy : enemies)
      {
        if (projectile->collidesWith(*enemy))
        {
          // Remove enemy and projectile
        }
      }
    }
    else
    {
      if (projectile->collidesWith(*player))
      {
        // Remove player and projectile
      }
    }
  }
}

void Logic::World::update()
{
  checkPlayerCollisions();
  checkProjectileCollisions();
  destroyEntities();

  player->update();


  for (auto& platform : platforms)
    platform->update();

  for (auto& enemy : enemies)
    enemy->update();

  for (auto& bonus : bonuses)
    bonus->update();

  for (auto& tile : tiles)
    tile->update();

  for (auto& projectile : projectiles)
    projectile->update();

  Camera::getInstance()->updateBaseHeight(
      player->getPosition(), player->getVelocity().y);
}

void Logic::World::setPlayerState(const PlayerState& state)
{
  player->setPlayerState(state);
}

void Logic::World::destroyEntities()
{
  destroyPlatforms(); 
}

void Logic::World::destroyPlatforms()
{
  std::vector<int> toBeDeleted;

  for (int i = 0; i < platforms.size(); ++i)
    if (Camera::getInstance()->isOutOfLowerBounds(platforms[i]->getPosition())) toBeDeleted.push_back(i);
  
  for (int i = 0; i < toBeDeleted.size(); ++i)
    toBeDeleted[i] -= i;

  for (const auto& index : toBeDeleted)
    platforms.erase(platforms.begin()+index);

}
