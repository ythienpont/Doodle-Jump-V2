#include "Enemy.h"

Logic::Enemy::Enemy(const Vec2D& pos) : Logic::Model(pos, ENEMY_WIDTH, ENEMY_HEIGHT), Living(ENEMY_HP) { }
Logic::Enemy::Enemy(const Vec2D& pos, const double& width, const double& height, const int hp) : Logic::Model(pos, width, height), Living(hp) { }
Logic::ShootingEnemy::ShootingEnemy(const Vec2D& pos) : Logic::Enemy(pos, SENEMY_WIDTH, SENEMY_HEIGHT, SHOOTINGENEMY_HP) { }

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

void Logic::ShootingEnemy::update()
{
  int shoot = Random::getInstance()->getValue() % SHOOTING_CHANCE; 
  
  switch (shoot)
  {
    case 0:
    {
      shooting = true;
      break;
    }
    default:
    shooting = false;
    break;
  }

  notifyObservers();
  if (isDead()) moveOutOfBounds();
}
