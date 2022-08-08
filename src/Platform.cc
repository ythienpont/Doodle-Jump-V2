#include "Platform.h"

int getNumberInRange(const int range)
{
  bool sign = Logic::Random::getInstance()->getValue()%2;
  return sign*(-1)*(Logic::Random::getInstance()->getValue()%(range)+1);// I never want the number to be 0
}

Logic::Platform::Platform(const Vec2D& startPos) : Model(startPos, PWIDTH, PHEIGHT), jumpedOn(false), credits(5) { }

Logic::Platform::Platform(const Vec2D& startPos, const int creds) : Model(startPos, PWIDTH, PHEIGHT), jumpedOn(false), credits(creds) { }

int Logic::Platform::getCredits() const
{
  return credits;
}

Logic::HPlatform::HPlatform(const Vec2D& pos) : Platform(pos, 2), Moving(Vec2D(1,0)) { }

Logic::VPlatform::VPlatform(const Vec2D& pos) : Platform(pos, 2), Moving(Vec2D(0,1)), startPos(pos) { }

Logic::TempPlatform::TempPlatform(const Vec2D& pos) : Platform(pos, 1) { }

Logic::HTelePlatform::HTelePlatform(const Vec2D& pos) : Platform(pos, 2), startPos(pos) { }

Logic::VTelePlatform::VTelePlatform(const Vec2D& pos) : Platform(pos, 2), startPos(pos) { }

void Logic::Platform::update() { 
  notifyObservers();
}

void Logic::HTelePlatform::jumpOn()
{
  int newX = newX + getNumberInRange(HRANGE);
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
