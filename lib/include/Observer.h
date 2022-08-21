#ifndef OBSERVER_H
#define OBSERVER_H

#include "Vec2D.h"

namespace Logic
{
  class Observer
  {
  public:
    virtual void update(const Vec2D& position)=0;
  };
}
#endif //OBSERVER_H
