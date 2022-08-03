#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Model.h"

namespace Logic
{
  class Projectile : public Entity::Model, Moving
  {
  private:
    bool friendly;
  public:
    bool isFriendly() const;
  };
}

#endif //PROJECTILE_H
