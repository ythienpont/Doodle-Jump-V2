#include "../include/World.h"

int xTileAmt = 0;
int yTileAmt = 0;

Logic::World::World(std::shared_ptr<AbstractFactory> factory) : difficulty(STARTINGDIFF), camera()
{
  player = factory->createPlayer(Vec2D(240,100), camera.toPixelCoordinates(Vec2D(240,100)));
  platforms.push_back(factory->createPlatform(Vec2D(240,60), camera.toPixelCoordinates(Vec2D(240,60))));
  xTileAmt = std::round(SCREENW/TILEWIDTH)+1;
  yTileAmt = std::round(SCREENH/TILEHEIGHT)+1;

  for (int y = 0; y < xTileAmt; ++y)
  {
    for (int x = 0; x < yTileAmt; ++x)
    {
      Vec2D pos(x*TILEWIDTH,y*TILEHEIGHT);
      tiles.push_back(factory->createBGTile(pos, camera.toPixelCoordinates(pos)));
    }
  }
}

Logic::World::~World()
{
  player = nullptr;
  enemies.clear();
  bonuses.clear();
  platforms.clear();
  tiles.clear();
  projectiles.clear();
  effects.clear();
}

void Logic::World::checkPlayerCollisions(std::shared_ptr<AbstractFactory> factory)
{
  // Loop over enemies, doesn't matter if going down
  for (auto& enemy : enemies)
  {
    if (player->collidesWith(*enemy))
    {
      int health = player->getHP();
      player->hit();
      if (player->getHP() == health-1)
      {
        effects.push_back(factory->createFriendlyHitEffect());
        enemy->kill();
        score.addDelta(enemy->getScoreDelta());
      }

      return; // Only one collision each loop
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

        score.addDelta(bonus->getScoreDelta());

        if (bonus->getScoreDelta() < 0)
        {
          effects.push_back(factory->createFriendlyHitEffect());
        }
        else
        {
          effects.push_back(factory->createEnemyHitEffect());
        }

        return; // Only one collision each loop
      }
    }
    for (auto& platform : platforms)
    {
      if (player->collidesWith(*platform))
      {
        if (platform->hasBeenJumpedOn())
        {
          score.addDelta(platform->getScoreDelta());
        }
        player->jump();
        platform->jumpOn();

        return; // Only one collision each loop
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
      Vec2D pos(enemy->getPosition()+Vec2D(ENEMY_WIDTH/2,0));

      projectiles.push_back(factory->createEnemyBullet(pos, camera.toPixelCoordinates(pos), enemy->getBulletVelocity(player->getPosition())));
      enemy->reset();
    }
  }
}

void Logic::World::spawnPlayerBullet(std::shared_ptr<AbstractFactory> factory)
{
  Vec2D pos(player->getPosition().x+PLAYER_WIDTH/2,player->getPosition().y);
  projectiles.push_back(factory->createPlayerBullet(pos, camera.toPixelCoordinates(pos)));
}

void Logic::World::spawnEnemy(std::shared_ptr<AbstractFactory> factory)
{
  Vec2D randomPos(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH),
      getHighestPlatformPosition().y+PLATFORM_OFFSET);

  platforms.push_back(factory->createPlatform(randomPos, camera.toPixelCoordinates(randomPos)));

  randomPos = Vec2D(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH), randomPos.y-(Random::getInstance()->getValue()% (int) PLATFORM_OFFSET));

  platforms.push_back(factory->createPlatform(randomPos, camera.toPixelCoordinates(randomPos)));

  bool throwing = Random::getInstance()->getValue()%2;

  if (throwing)
  {
    randomPos += (Vec2D(SENEMY_WIDTH/2,PHEIGHT));
    enemies.push_back(factory->createShootingEnemy(randomPos, camera.toPixelCoordinates(randomPos)));
  }
  else
  {
    randomPos += (Vec2D(ENEMY_WIDTH/2,PHEIGHT));
    enemies.push_back(factory->createEnemy(randomPos, camera.toPixelCoordinates(randomPos)));
  }
}

void Logic::World::spawnBonus(std::shared_ptr<AbstractFactory> factory)
{
  Vec2D randomPos(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH),
      getHighestPlatformPosition().y+PLATFORM_OFFSET);
  Vec2D randomPixelPos = camera.toPixelCoordinates(randomPos);

  platforms.push_back(factory->createPlatform(randomPos,randomPixelPos));

  randomPos = Vec2D(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH), randomPos.y-(Random::getInstance()->getValue()% (int) PLATFORM_OFFSET));
  randomPixelPos = camera.toPixelCoordinates(randomPos);

  platforms.push_back(factory->createPlatform(randomPos, randomPixelPos));

  randomPos += Vec2D(PWIDTH/2-(double) BONUS_WIDTH/2,PHEIGHT);
  randomPixelPos = camera.toPixelCoordinates(randomPos);
  int bonusType = Random::getInstance()->getValue() % BONUS_AMT;
  switch (bonusType)
  {
    case 0:
      bonuses.push_back(factory->createSpikes(randomPos - Vec2D(PWIDTH/2-(double) BONUS_WIDTH/2,0), camera.toPixelCoordinates(randomPos-Vec2D(20,0))));
      break;
    case 1:
      bonuses.push_back(factory->createHeart(randomPos, randomPixelPos));
      break;
    case 2:
      bonuses.push_back(factory->createJetpack(randomPos, randomPixelPos));
      break;
     default:
      bonuses.push_back(factory->createSpring(randomPos, randomPixelPos));
      break;
  }
}

void Logic::World::spawnPlatform(std::shared_ptr<AbstractFactory> factory, const Vec2D& pos, const int platformType)
{
  Vec2D pixelPos = camera.toPixelCoordinates(pos);
    switch (platformType)
    {
      case 0:
        platforms.push_back(factory->createHPlatform(pos, pixelPos));
        break;
      case 1:
        platforms.push_back(factory->createVPlatform(pos, pixelPos));
        break;
      case 2:
        platforms.push_back(factory->createTempPlatform(pos, pixelPos));
        break;
      case 3:
        spawnEnemy(factory);
        break;
      case 4:
        platforms.push_back(factory->createHTelePlatform(pos, pixelPos));
        break;
      case 5:
        platforms.push_back(factory->createVTelePlatform(pos, pixelPos));
        break;
      case 6:
        spawnBonus(factory);
        break;
      default:
        platforms.push_back(factory->createPlatform(pos, pixelPos));
        break;
    }
}

void Logic::World::spawnPlatforms(std::shared_ptr<AbstractFactory> factory)
{
  while (!camera.isOutOfUpperBounds(getHighestPlatformPosition()))
  {
    int platformType = Random::getInstance()->getValue() % difficulty;

    Vec2D randomPos(Random::getInstance()->getValue() % (int) (SCREENW-PWIDTH),
        getHighestPlatformPosition().y+(PLATFORM_OFFSET+(STARTINGDIFF-difficulty)));

    spawnPlatform(factory, randomPos, platformType);
  }
}

std::vector<std::shared_ptr<Logic::Observer> > Logic::World::getView() const
{
  std::vector<std::shared_ptr<Logic::Observer> > sprites;

  for (auto& tile : tiles)
    sprites.push_back(tile->view);

  for (auto& platform : platforms)
    sprites.push_back(platform->view);

  for (auto& bonus : bonuses)
    sprites.push_back(bonus->view);

  for (auto& enemy : enemies)
    sprites.push_back(enemy->view);

  for (auto& projectile : projectiles)
    sprites.push_back(projectile->view);

  sprites.push_back(player->view);

  for (auto& effect : effects)
    sprites.push_back(effect->view);

  return sprites;
}

void Logic::World::checkProjectileCollisions(std::shared_ptr<AbstractFactory> factory)
{
  for (auto& projectile : projectiles)
  {
    if (projectile->isFriendly())
    {
      for (auto& enemy : enemies)
      {
        if (projectile->collidesWith(*enemy))
        {
          score.addDelta(-enemy->getScoreDelta());
          effects.push_back(factory->createEnemyHitEffect());
          enemy->hit();
          projectile->moveOutOfBounds();
        }
      }
    }
    else
    {
      if (projectile->collidesWith(*player))
      {
        effects.push_back(factory->createFriendlyHitEffect());
        player->hit();
        projectile->moveOutOfBounds();
      }
    }
  }
}

void Logic::World::update(std::shared_ptr<AbstractFactory> factory)
{
  destroyEntities();
  if (!player->isDead())
  {
    spawnEntities(factory);
    checkPlayerCollisions(factory);
    checkProjectileCollisions(factory);
  }

  player->update();
  player->setPixelPos(camera.toPixelCoordinates(player->getPosition()));

  difficulty = std::max(14,STARTINGDIFF - ((int) player->getPosition().y / 10000));

  for (auto& platform : platforms)
  {
    platform->update();
    platform->setPixelPos(camera.toPixelCoordinates(platform->getPosition()));
  }

  for (auto& enemy : enemies)
  {
    enemy->update();
    enemy->checkIfNeedToShoot(player->getPosition());
    enemy->setPixelPos(camera.toPixelCoordinates(enemy->getPosition()));
  }

  for (auto& bonus : bonuses)
  {
    bonus->update();
    bonus->setPixelPos(camera.toPixelCoordinates(bonus->getPosition()));
  }

  updateTiles();

  for (auto& projectile : projectiles)
  {
    projectile->update();
    projectile->setPixelPos(camera.toPixelCoordinates(projectile->getPosition()));
  }

  score.addDelta(camera.updateBaseHeight(
      player->getPosition(), player->getVelocity().y));
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
  clearEffects();
}

void Logic::World::clearEffects()
{
  effects.clear();
}

void Logic::World::destroyPlatforms()
{
  std::vector<int> toBeDeleted;

  for (int i = 0; i < platforms.size(); ++i)
    if (camera.isOutOfLowerBounds(platforms[i]->getPosition())) toBeDeleted.push_back(i);

  for (int i = 0; i < toBeDeleted.size(); ++i)
    toBeDeleted[i] -= i;

  for (const auto& index : toBeDeleted)
    platforms.erase(platforms.begin()+index);

}

void Logic::World::destroyBonuses()
{
  std::vector<int> toBeDeleted;

  for (int i = 0; i < bonuses.size(); ++i)
    if (camera.isOutOfLowerBounds(bonuses[i]->getPosition())) toBeDeleted.push_back(i);

  for (int i = 0; i < toBeDeleted.size(); ++i)
    toBeDeleted[i] -= i;

  for (const auto& index : toBeDeleted)
    bonuses.erase(bonuses.begin()+index);

}

void Logic::World::destroyEnemies()
{
  std::vector<int> toBeDeleted;

  for (int i = 0; i < enemies.size(); ++i)
    if (camera.isOutOfLowerBounds(enemies[i]->getPosition())) toBeDeleted.push_back(i);

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
      if (camera.isOutOfUpperBounds(projectiles[i]->getPosition()) or camera.isOutOfLowerBounds(projectiles[i]->getPosition()))
        toBeDeleted.push_back(i);
    }
    else
    {
      if (camera.isOutOfBounds(projectiles[i]->getPosition())) toBeDeleted.push_back(i);
    }
  }

  for (int i = 0; i < toBeDeleted.size(); ++i)
    toBeDeleted[i] -= i;

  for (const auto& index : toBeDeleted)
    projectiles.erase(projectiles.begin()+index);
}

int Logic::World::getScore() const
{
  return score.getAmount();
}

int Logic::World::getPlayerHP() const
{
  return player->getHP();
}

bool Logic::World::isGameOver() const
{
  return camera.isOutOfLowerBounds(player->getPosition());
}

double Logic::World::getHighestTileY() const
{
  double highest = 0;

  for (int i = 0; i < yTileAmt; ++i)
    if (tiles[xTileAmt*i]->getPosition().y > highest) highest = tiles[xTileAmt*i]->getPosition().y;

  return highest;
}

void Logic::World::updateTiles()
{
  for (int i = 0; i < yTileAmt; ++i)
  {
    if (camera.isOutOfLowerBounds(tiles[xTileAmt*i]->getPosition(), TILEHEIGHT))
    {
      double highestTileY = getHighestTileY();
      for (int j = 0; j < xTileAmt; ++j)
      {
        tiles[i*yTileAmt+j]->setPosition(tiles[i*yTileAmt+j]->getPosition().x,highestTileY+TILEHEIGHT);
      }
    }
  }

  for (auto& tile : tiles)
  {
    tile->update();
    tile->setPixelPos(camera.toPixelCoordinates(tile->getPosition()));
  }
}
