#include "Platform.h"

int getNumberInRange(const int range)
{
  bool sign = Logic::Random::getInstance()->getValue()%2;
  return sign*(-1)*(Logic::Random::getInstance()->getValue()%(range)+1);// I never want the number to be 0
}

Logic::Platform::Platform(const Vec2D& startPos) : Model(startPos, PWIDTH, PHEIGHT), jumpedOn(false), credits(5) { }

Logic::Platform::Platform(const Vec2D& startPos, const int creds) : Model(startPos, PWIDTH, PHEIGHT), jumpedOn(false), credits(creds) { }

void Logic::Platform::jumpOn()
{
  jumpedOn = true;
}

int Logic::Platform::getCredits() const
{
  return credits;
}

bool Logic::Platform::hasBeenJumpedOn() const
{
  return jumpedOn;
}

Logic::HPlatform::HPlatform(const Vec2D& pos) : Platform(pos, 2), Moving(Vec2D(1,0)) { }

Logic::VPlatform::VPlatform(const Vec2D& pos) : Platform(pos, 2), Moving(Vec2D(0,1)), startPos(pos) { }

Logic::TempPlatform::TempPlatform(const Vec2D& pos) : Platform(pos, 1) { }

Logic::HTelePlatform::HTelePlatform(const Vec2D& pos) : Platform(pos, 2), startPos(pos) { }

Logic::VTelePlatform::VTelePlatform(const Vec2D& pos) : Platform(pos, 2), startPos(pos) { }

void Logic::Platform::update() { 
  notifyObservers();
}

void Logic::HTelePlatform::update()
{
  setPosition(startPos+Vec2D(getNumberInRange(HRANGE),0));
  notifyObservers();
}

void Logic::VTelePlatform::update()
{
  setPosition(startPos+Vec2D(0,getNumberInRange(VRANGE)));
  notifyObservers();
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

void Logic::TempPlatform::update()
{
  if (hasBeenJumpedOn()) move(Vec2D(0, -10000)); // Make sure object is out of bounds
  notifyObservers();
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
