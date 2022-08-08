#include "Enemy.h"

Logic::Enemy::Enemy(const Vec2D& pos) : Logic::Model(pos, ENEMY_WIDTH, ENEMY_HEIGHT), Living(ENEMY_HP) { }
Logic::ShootingEnemy::ShootingEnemy(const Vec2D& pos) : Logic::Model(pos, SENEMY_WIDTH, SENEMY_HEIGHT), Living(SHOOTINGENEMY_HP) { }

void Logic::Enemy::update()
{
  notifyObservers();
  if (isDead()) moveOutOfBounds();
}

void Logic::ShootingEnemy::update()
{
  notifyObservers();
  if (isDead()) moveOutOfBounds();
}
