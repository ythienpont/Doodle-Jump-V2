#ifndef BGTILE_H
#define BGTILE_H

#include "Model.h"

const double TILEWIDTH = 80;
const double TILEHEIGHT = 160;

namespace Logic
{
  class BGTile : public Model
  {
  public:
    BGTile(const Vec2D& pos);
    void update() override;
  };
}

#endif //BGTILE_H
