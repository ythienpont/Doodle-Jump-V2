#include "Enemy.h"
#include <iostream>

Logic::Enemy::Enemy(const Vec2D& pos) : Logic::Model(pos, ENEMY_WIDTH, ENEMY_HEIGHT, ENEMY_DELTA), Living(ENEMY_HP) { }
Logic::Enemy::Enemy(const Vec2D& pos, const double& width, const double& height, const int hp, const int scoreD) : Logic::Model(pos, width, height, scoreD), Living(hp) { }
Logic::ShootingEnemy::ShootingEnemy(const Vec2D& pos) : Logic::Enemy(pos, SENEMY_WIDTH, SENEMY_HEIGHT, SHOOTINGENEMY_HP, SENEMY_DELTA), shooting(false) { }

void Logic::Enemy::update()
{
  notifyObservers();
  if (isDead()) moveOutOfBounds();
}

bool Logic::Enemy::isShooting() const
{
  return false;
}


bool Logic::ShootingEnemy::isShooting() const
{
  return shooting;
}

void Logic::Enemy::reset() { }

void Logic::ShootingEnemy::reset()
{
  shooting = false;
}

void Logic::ShootingEnemy::hit()
{
  shooting = true;
  addHP(-1);
}
