#include "Platform.h"

int getNumberInRange(const int range)
{
  bool sign = Logic::Random::getInstance()->getValue()%2;
  return std::pow(-1,sign)*(Logic::Random::getInstance()->getValue()%(range)+1);// I never want the number to be 0
}

Logic::Platform::Platform(const Vec2D& startPos) : Model(startPos, PWIDTH, PHEIGHT, PLATDELTA), jumpedOn(false) { }

Logic::Platform::Platform(const Vec2D& startPos, const int scoreD) : Model(startPos, PWIDTH, PHEIGHT, scoreD), jumpedOn(false) { }

Logic::HPlatform::HPlatform(const Vec2D& pos) : Platform(pos, HPLATDELTA), Moving(Vec2D(1,0)) { }

Logic::VPlatform::VPlatform(const Vec2D& pos) : Platform(pos, VPLATDELTA), Moving(Vec2D(0,1)), startPos(pos) { }

Logic::TempPlatform::TempPlatform(const Vec2D& pos) : Platform(pos, TELEDELTA) { }

Logic::HTelePlatform::HTelePlatform(const Vec2D& pos) : Platform(pos, TELEDELTA), startPos(pos) { }

Logic::VTelePlatform::VTelePlatform(const Vec2D& pos) : Platform(pos, VPLATDELTA), startPos(pos) { }

void Logic::Platform::update() {
  notifyObservers();
}

void Logic::HTelePlatform::jumpOn()
{
  int newX = startPos.x + getNumberInRange(HRANGE);
  if (newX <= SCREENW/2)
  {
    newX = std::max(0,newX);
  }
  else
  {
    newX = std::min((int)(SCREENW-PWIDTH),newX);
  }

  setPosition(Vec2D(newX,getPosition().y));
}

void Logic::VTelePlatform::jumpOn()
{
  setPosition(startPos+Vec2D(0,getNumberInRange(VRANGE)));
}

void Logic::VPlatform::update()
{
  if (getPosition().y >= startPos.y + VRANGE)
  {
    setVelocity(Vec2D(0,-1));
  }
  else if (getPosition().y <= startPos.y - VRANGE)
  {
    setVelocity(Vec2D(0,1));
  }

  move(getVelocity());
  notifyObservers();
}

void Logic::TempPlatform::jumpOn()
{
  moveOutOfBounds();
}

void Logic::HPlatform::update()
{
  if (getPosition().x <= 0)
  {
    setVelocity(Vec2D(1,0));
  }
  else if (getPosition().x >= SCREENW-PWIDTH)
  {
    setVelocity(Vec2D(-1,0));
  }

  move(getVelocity());
  notifyObservers();
}
