#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Model.h"

namespace Logic
{
  class Projectile : public Model, Moving
  {
  private:
    bool friendly;
  public:
    bool isFriendly() const;
    virtual void update()=0;
  protected:
    Projectile(const Vec2D& pos, const bool isFriendly);
  };

  class PlayerBullet : public Projectile
  {
  public:
    PlayerBullet(const Vec2D& pos);
    void update() override;
  };

  class EnemyBullet : public Projectile
  {
  public:
    EnemyBullet(const Vec2D& pos);
    void update() override;
  };
}

#endif //PROJECTILE_H
