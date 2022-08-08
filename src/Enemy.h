#ifndef ENEMY_H
#define ENEMY_H

#include "Model.h"

const int ENEMY_HP = 1;
const int SHOOTINGENEMY_HP = 2;
const double SENEMY_WIDTH = 40;
const double SENEMY_HEIGHT = 40;
const double ENEMY_HEIGHT = 30;
const double ENEMY_WIDTH = 30;
const double THROWING_INTERVAL = 10; // Throw an obstacle every 10 seconds

namespace Logic
{
  class Enemy : public Model, public Living
  {
  public:
    Enemy(const Vec2D& pos);
    void update() override;
  };

  class ShootingEnemy : public Model, public Living
  {
  public:
    ShootingEnemy(const Vec2D& pos);
    void update() override;
  };
}

#endif //ENEMY_H
