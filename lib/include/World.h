#ifndef WORLD_H
#define WORLD_H

#include "Player.h"
#include "Platform.h"
#include <memory>
#include "BGTile.h"
#include "Bonus.h"
#include "Enemy.h"
#include "Projectile.h"
#include "BGTile.h"
#include "AbstractFactory.h"
#include "Score.h"

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
    std::vector<std::unique_ptr<Effect> > effects;

    int difficulty;
    Score score;
    Camera camera;

    void checkPlayerCollisions(std::shared_ptr<AbstractFactory> factory);
    void checkProjectileCollisions(std::shared_ptr<AbstractFactory> factory);
    Vec2D getHighestPlatformPosition() const;
    void spawnPlatforms(std::shared_ptr<AbstractFactory> factory);
    void spawnPlatform(std::shared_ptr<AbstractFactory> factory, const Vec2D& pos, const int platformType);
    void spawnEnemy(std::shared_ptr<AbstractFactory> factory);
    void spawnBonus(std::shared_ptr<AbstractFactory> factory);
    void spawnEntities(std::shared_ptr<AbstractFactory> factory);
    void spawnPlayerBullet(std::shared_ptr<AbstractFactory> factory);
    void destroyEntities();
    void destroyPlatforms();
    void destroyBonuses();
    void destroyEnemies();
    void destroyProjectiles();
    void clearEffects();
    void updateTiles();
    double getHighestTileY() const;
  public:
    World(std::shared_ptr<AbstractFactory> factory);
    ~World();
    void update(std::shared_ptr<AbstractFactory> factory);
    std::vector<std::shared_ptr<Observer> > getView() const;
    void setPlayerState(const PlayerState& state);
    int getScore() const;
    int getPlayerHP() const;
    bool isGameOver() const;
  };

}
#endif //WORLD_H
