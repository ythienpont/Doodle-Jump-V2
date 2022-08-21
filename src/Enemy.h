#ifndef ENEMY_H
#define ENEMY_H

#include "Model.h"
#include "Random.h"

const int ENEMY_HP = 1;
const int SHOOTINGENEMY_HP = 3;
const double SENEMY_WIDTH = 40;
const double SENEMY_HEIGHT = 40;
const double ENEMY_HEIGHT = 30;
const double ENEMY_WIDTH = 30;
const int SHOOTING_CHANCE = 100;
const int ENEMY_DELTA = 500;
const int SENEMY_DELTA = 1000;
const int ENEMYRANGE = 300;
const double BULLETSPEED = 5;
const double THROWINGSPEED = 15;

namespace Logic
{
  class Enemy : public Model, public Living
  {
  public:
    bool hasShot;
  public:
    explicit Enemy(const Vec2D& pos);
    void update() override;
    virtual bool isShooting() const;
    virtual void reset();
    virtual void checkIfNeedToShoot(const Vec2D& pos); // Awful function name
    virtual Vec2D getBulletVelocity(const Vec2D& playerPos) const;
  protected:
    bool shooting;
    Enemy(const Vec2D& pos, const double& width, const double& height, const int hp, const int scoreD);
  };

  class ShootingEnemy : public Enemy
  {
  public:
    explicit ShootingEnemy(const Vec2D& pos);
    bool isShooting() const override;
    void hit() override;
    void checkIfNeedToShoot(const Vec2D& pos) override;
    Vec2D getBulletVelocity(const Vec2D& playerPos) const override;
  };
}

#endif //ENEMY_H
