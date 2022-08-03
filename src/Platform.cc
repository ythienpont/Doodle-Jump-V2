#include "Platform.h"

int getNumberInRange(const int range)
{
  bool sign = Logic::Random::getInstance()->getValue()%2;
  return sign*(-1)*(Logic::Random::getInstance()->getValue()%(range)+1);// I never want the number to be 0
}

Logic::Platform::Platform(const Vec2D& startPos) : Model(startPos, PWIDTH, PHEIGHT), jumpedOn(false) { }

void Logic::Platform::jumpOn()
{
  jumpedOn = true;
}

void Logic::Platform::update() { }

void Logic::HTelePlatform::update()
{
  setPosition(startPos+Vec2D(getNumberInRange(HRANGE),0));
}

void Logic::VTelePlatform::update()
{
  setPosition(startPos+Vec2D(0,getNumberInRange(VRANGE)));
}

void Logic::VPlatform::update()
{
  if (getPosition().y == startPos.y + HRANGE)
  {
    setVelocity(Vec2D(0,-1)); 
  }
  else if (getPosition().y == startPos.y - HRANGE)
  {
    setVelocity(Vec2D(0,1)); 
  }

  move(getVelocity());
}
