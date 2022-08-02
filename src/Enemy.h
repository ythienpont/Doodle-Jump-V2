#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

const double throwingInterval = 10; // Throw an obstacle every 10 seconds

class Enemy : public Entity
{
  int HP;
};

class ThrowingEnemy : public Enemy
{

};

#endif //ENEMY_H
