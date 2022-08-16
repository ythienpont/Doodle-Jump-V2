#include "World.h"
#include <iostream>

Logic::World::World(std::shared_ptr<AbstractFactory> factory) : difficulty(STARTINGDIFF)
{
  player = factory->createPlayer(Vec2D(240,100));
  platforms.push_back(factory->createPlatform(Vec2D(240,60)));
}

void Logic::World::checkPlayerCollisions()
{
  // Loop over enemies, doesn't matter if going down
  for (auto& enemy : enemies)
  {
    if (player->collidesWith(*enemy))
    {
      player->hit();
      enemy->kill();
    }
  }
  if (player->goingDown())
  {
    // Loop over all platforms and bonuses
    for (auto& bonus : bonuses)
    {
      if (player->collidesWith(*bonus))
      {
        player->addBonus(bonus);
        bonus->jumpOn();
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

  if (player->isShooting())
  {
    spawnPlayerBullet(factory);
    player->reset();
  }

  for (auto& enemy : enemies)
  {
    if (enemy->isShooting())
    {
      projectiles.push_back(factory->createEnemyBullet(enemy->getPosition()+Vec2D(20,0)));
    }
  }
}

void Logic::World::spawnPlayerBullet(std::shared_ptr<AbstractFactory> factory)
{
  projectiles.push_back(factory->createPlayerBullet(Vec2D(player->getPosition().x+PLAYER_WIDTH/2,player->getPosition().y)));
}

void Logic::World::spawnEnemy(std::shared_ptr<AbstractFactory> factory)
{
  Vec2D randomPos(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH),
      getHighestPlatformPosition().y+PLATFORM_OFFSET);

  platforms.push_back(factory->createPlatform(randomPos)); 

  randomPos = Vec2D(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH), randomPos.y-(Random::getInstance()->getValue()% (int) PLATFORM_OFFSET));

  platforms.push_back(factory->createPlatform(randomPos));

  bool shooting = Random::getInstance()->getValue()%2;

  if (shooting)
  {
    enemies.push_back(factory->createShootingEnemy(Vec2D(randomPos.x+10,randomPos.y+16)));
  }
  else
  {
    enemies.push_back(factory->createEnemy(Vec2D(randomPos.x+16,randomPos.y+16)));
  }
}

void Logic::World::spawnBonus(std::shared_ptr<AbstractFactory> factory)
{
  Vec2D randomPos(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH),
      getHighestPlatformPosition().y+PLATFORM_OFFSET);

  platforms.push_back(factory->createPlatform(randomPos)); 

  randomPos = Vec2D(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH), randomPos.y-(Random::getInstance()->getValue()% (int) PLATFORM_OFFSET));

  platforms.push_back(factory->createPlatform(randomPos));

  int bonusType = Random::getInstance()->getValue() % BONUS_AMT;
  switch (bonusType)
  {
    case 0:
      bonuses.push_back(factory->createSpikes(Vec2D(randomPos.x,randomPos.y+16)));
      break;
    case 1:
      bonuses.push_back(factory->createHeart(Vec2D(randomPos.x+20,randomPos.y+16)));
      break;
    case 2:
      bonuses.push_back(factory->createJetpack(Vec2D(randomPos.x+20,randomPos.y+16)));
      break;
     default:
      bonuses.push_back(factory->createSpring(Vec2D(randomPos.x+20,randomPos.y+16)));
      break;
  }
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
      case 3:
        spawnEnemy(factory);
        break;
      case 4:
        platforms.push_back(factory->createHTelePlatform(pos));
        break;
      case 5:
        platforms.push_back(factory->createVTelePlatform(pos));
        break;
      case 6:
        spawnBonus(factory);
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
          enemy->hit();
      }
    }
    else
    {
      if (projectile->collidesWith(*player))
        player->hit();
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
  destroyBonuses();
  destroyEnemies();
  destroyProjectiles();
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

void Logic::World::destroyBonuses()
{
  std::vector<int> toBeDeleted;

  for (int i = 0; i < bonuses.size(); ++i)
    if (Camera::getInstance()->isOutOfLowerBounds(bonuses[i]->getPosition())) toBeDeleted.push_back(i);

  for (int i = 0; i < toBeDeleted.size(); ++i)
    toBeDeleted[i] -= i;

  for (const auto& index : toBeDeleted)
    bonuses.erase(bonuses.begin()+index);

}

void Logic::World::destroyEnemies()
{
  std::vector<int> toBeDeleted;

  for (int i = 0; i < enemies.size(); ++i)
    if (Camera::getInstance()->isOutOfLowerBounds(enemies[i]->getPosition())) toBeDeleted.push_back(i);

  for (int i = 0; i < toBeDeleted.size(); ++i)
    toBeDeleted[i] -= i;

  for (const auto& index : toBeDeleted)
    enemies.erase(enemies.begin()+index);
}

void Logic::World::destroyProjectiles()
{
  std::vector<int> toBeDeleted;

  for (int i = 0; i < projectiles.size(); ++i)
  { if (projectiles[i]->isFriendly())
    {
      if (Camera::getInstance()->isOutOfUpperBounds(projectiles[i]->getPosition())) toBeDeleted.push_back(i);
    }
    else
    {
      if (Camera::getInstance()->isOutOfLowerBounds(projectiles[i]->getPosition())) toBeDeleted.push_back(i);
    }
  }

  for (int i = 0; i < toBeDeleted.size(); ++i)
    toBeDeleted[i] -= i;

  for (const auto& index : toBeDeleted)
    projectiles.erase(projectiles.begin()+index);
}
