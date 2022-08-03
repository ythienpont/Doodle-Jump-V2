#ifndef OBSERVER_H
#define OBSERVER_H 

#include "Vec2D.h"

class Observer 
{
  virtual void update(const Vec2D& position) = 0;
};

#endif //OBSERVER_H
