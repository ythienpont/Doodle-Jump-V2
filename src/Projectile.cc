#include "Projectile.h"

bool Logic::Projectile::isFriendly() const 
{
  return friendly;
}

Logic::Projectile::Projectile(const Vec2D& pos, const bool isFriendly) : Model(pos, 3, 10), friendly(isFriendly), Moving(Vec2D(0,10)){ }

Logic::PlayerBullet::PlayerBullet(const Vec2D& pos) : Projectile(pos, true) { }
Logic::EnemyBullet::EnemyBullet(const Vec2D& pos) : Projectile(pos, false) { }

void Logic::PlayerBullet::update()
{
  move(Vec2D(0,10));
  notifyObservers();
}

void Logic::EnemyBullet::update()
{
  move(Vec2D(0,-10));
}
