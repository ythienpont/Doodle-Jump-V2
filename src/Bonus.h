#ifndef BONUS_H
#define BONUS_H

#include "Entity.h"

class Bonus : public Entity
{
private:
  double duration;
  double jump_multiplier;
  double velocity;
  bool invincible;
public:
};

#endif //BONUS_H
