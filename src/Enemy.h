#ifndef ENEMY_H
#define ENEMY_H

#include "Model.h"
#include "Random.h"

const int ENEMY_HP = 1;
const int SHOOTINGENEMY_HP = 2;
const double SENEMY_WIDTH = 40;
const double SENEMY_HEIGHT = 40;
const double ENEMY_HEIGHT = 30;
const double ENEMY_WIDTH = 30;
const int SHOOTING_CHANCE = 100;

namespace Logic
{
  class Enemy : public Model, public Living
  {
  public:
    Enemy(const Vec2D& pos);
    void update() override;
    virtual bool isShooting() const;
  protected:
    Enemy(const Vec2D& pos, const double& width, const double& height, const int hp);
  };

  class ShootingEnemy : public Enemy
  {
    bool shooting;
  public:
    ShootingEnemy(const Vec2D& pos);
    void update() override;
    bool isShooting() const override;
  };
}

#endif //ENEMY_H
