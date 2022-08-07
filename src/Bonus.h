#ifndef BONUS_H
#define BONUS_H

#include "Model.h"

namespace Logic
{
  class Bonus : public Model
  {
  private:
    double duration;
    double jump_multiplier;
    double velocity;
    bool invincible;
  public:
  };
}

#endif //BONUS_H
