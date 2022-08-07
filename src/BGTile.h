#ifndef BGTILE_H
#define BGTILE_H

#include "Model.h"

namespace Logic
{
  class BGTile : public Model
  {
  public:
    BGTile(const Vec2D& pos);
    void update() override { }
  };
}

#endif //BGTILE_H
