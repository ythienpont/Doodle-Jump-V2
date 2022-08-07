#ifndef ENEMY_H
#define ENEMY_H

#include "Model.h"

const double THROWING_INTERVAL = 10; // Throw an obstacle every 10 seconds

namespace Logic
{
  class Enemy : public Model
  {
    int HP;
  public:
  Enemy(const Vec2D& pos);
    void update() override { }
  };

  class ThrowingEnemy : public Enemy
  {

  };
}

#endif //ENEMY_H
