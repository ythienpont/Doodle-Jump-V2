#ifndef WORLD_H
#define WORLD_H

#include "Player.h"
#include "Platform.h"
#include <memory>
#include "BGTile.h"
#include "Bonus.h"
#include "Enemy.h"
#include "Projectile.h"
#include "AbstractFactory.h"

const double PLATFORM_OFFSET = 180;
const int STARTINGDIFF = 30;

namespace Logic
{
  class World 
  {
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Platform> > platforms;
    std::vector<std::unique_ptr<Enemy> > enemies;
    std::vector<std::shared_ptr<Bonus> > bonuses;
    std::vector<std::unique_ptr<BGTile> > tiles;
    std::vector<std::unique_ptr<Projectile> > projectiles;

    int difficulty;

    void checkPlayerCollisions();
    void checkProjectileCollisions();
    Vec2D getHighestPlatformPosition() const;
    void spawnPlatforms(std::shared_ptr<AbstractFactory> factory);
    void spawnPlatform(std::shared_ptr<AbstractFactory> factory, const Vec2D& pos, const int platformType);
    void spawnEnemy(std::shared_ptr<AbstractFactory> factory);
    void spawnBonus(std::shared_ptr<AbstractFactory> factory);
    void spawnPlayerBullet(std::shared_ptr<AbstractFactory> factory);
    int getTotalCredits() const;
    void destroyEntities();
    void destroyPlatforms();
  public:
    World(std::shared_ptr<AbstractFactory> factory);
    void spawnEntities(std::shared_ptr<AbstractFactory> factory);
    void update();
    std::vector<std::shared_ptr<Representation::View> > getSprites() const;
    void setPlayerState(const PlayerState& state);
  };
}
#endif //WORLD_H
