#include "Enemy.h"
#include <iostream>

Logic::Enemy::Enemy(const Vec2D& pos) : Logic::Model(pos, ENEMY_WIDTH, ENEMY_HEIGHT, ENEMY_DELTA), Living(ENEMY_HP), shooting(false), hasShot(false){ }
Logic::Enemy::Enemy(const Vec2D& pos, const double& width, const double& height, const int hp, const int scoreD) : Logic::Model(pos, width, height, scoreD), Living(hp), shooting(false), hasShot(false) { }
Logic::ShootingEnemy::ShootingEnemy(const Vec2D& pos) : Logic::Enemy(pos, SENEMY_WIDTH, SENEMY_HEIGHT, SHOOTINGENEMY_HP, SENEMY_DELTA) { }

void Logic::Enemy::update()
{
  notifyObservers();
  if (isDead()) moveOutOfBounds();
}

void Logic::Enemy::checkIfNeedToShoot(const Vec2D& pos)
{
  if (isInRange(pos, ENEMYRANGE))
    shooting = true;
  else
  {
    shooting=false;
    hasShot = false;
  }
}

Vec2D Logic::Enemy::getBulletVelocity(const Vec2D& playerPos) const
{
    Vec2D vel = pathToObject(playerPos);
    vel.normalize();
    vel*=BULLETSPEED;

    return vel;
}

Vec2D Logic::ShootingEnemy::getBulletVelocity(const Vec2D& playerPos) const
{
  return Vec2D(0,-THROWINGSPEED);
}

void Logic::ShootingEnemy::checkIfNeedToShoot(const Vec2D& pos) { }

bool Logic::Enemy::isShooting() const
{
  return (shooting && !hasShot);
}


bool Logic::ShootingEnemy::isShooting() const
{
  return shooting;
}

void Logic::Enemy::reset()
{
  shooting = false;
  hasShot = true;
}

void Logic::ShootingEnemy::hit()
{
  shooting = true;
  addHP(-1);
}
