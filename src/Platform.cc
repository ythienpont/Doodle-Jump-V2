#include "Platform.h"

int getNumberInRange(const int range)
{
  bool sign = Random::getInstance()->getValue()%2;
  return sign*(-1)*(Random::getInstance()->getValue()%(range)+1);// I never want the number to be 0
}

Platform::Platform(const Vec2D& startPos) : Entity(startPos, PWIDTH, PHEIGHT), jumpedOn(false) { }

void Platform::jumpOn()
{
  jumpedOn = true;
}

void Platform::update() { }

void HTelePlatform::update()
{
  setPosition(startPos+Vec2D(getNumberInRange(HRANGE),0));
}

void VTelePlatform::update()
{
  setPosition(startPos+Vec2D(0,getNumberInRange(VRANGE)));
}

void VPlatform::update()
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
