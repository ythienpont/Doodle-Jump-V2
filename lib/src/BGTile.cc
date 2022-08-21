#include "../include/BGTile.h"

Logic::BGTile::BGTile(const Vec2D& pos) : Logic::Model(pos, TILEWIDTH, TILEHEIGHT, 0) { }

void Logic::BGTile::update()
{
  notifyObservers();
}
