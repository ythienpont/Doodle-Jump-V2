#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile : public Entity, Moving
{
private:
  bool friendly;
public:
  bool isFriendly() const;
};

#endif //PROJECTILE_H
