#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Model.h"

const int PROJECTILE_DELTA = 100;

namespace Logic
{
  class Projectile : public Model, public Moving
  {
  private:
    bool friendly;
  public:
    bool isFriendly() const;
    void update();
  protected:
    Projectile(const Vec2D& pos, const bool isFriendly, const Vec2D& velocity);
  };

  class PlayerBullet : public Projectile
  {
  public:
    PlayerBullet(const Vec2D& pos);
  };

  class EnemyBullet : public Projectile
  {
  public:
    EnemyBullet(const Vec2D& pos, const Vec2D& velocity);
  };
}

#endif //PROJECTILE_H
