#ifndef ENEMY_H
#define ENEMY_H

#include "Model.h"

const double THROWING_INTERVAL = 10; // Throw an obstacle every 10 seconds

namespace Logic
{
  class Enemy : public Model
  {
    int HP;
  };

  class ThrowingEnemy : public Enemy
  {

  };
}

#endif //ENEMY_H
