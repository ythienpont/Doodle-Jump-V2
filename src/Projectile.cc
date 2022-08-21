#include "Projectile.h"

bool Logic::Projectile::isFriendly() const
{
  return friendly;
}

Logic::Projectile::Projectile(const Vec2D& pos, const bool isFriendly, const Vec2D& velocity) : Model(pos, 10, 10, PROJECTILE_DELTA), friendly(isFriendly), Moving(velocity) { }

Logic::PlayerBullet::PlayerBullet(const Vec2D& pos) : Projectile(pos, true, Vec2D(0,30)) { }
Logic::EnemyBullet::EnemyBullet(const Vec2D& pos, const Vec2D& velocity) : Projectile(pos, false, velocity) { }

void Logic::Projectile::update()
{
  move(getVelocity());
  notifyObservers();
}
