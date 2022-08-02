#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"
#include "Random.h"

const int VRANGE = 10;
const int HRANGE = 10;
const double PWIDTH = 64;
const double PHEIGHT = 16;

class Platform : public Entity
{
  bool jumpedOn;
public:
  Platform(const Vec2D& startPos);
  virtual void update() override;
  bool hasBeenJumpedOn() const;
  void jumpOn();
};

class HPlatform : public Platform, Moving
{
public:
  void update() override;
};

class VPlatform : public Platform, Moving
{
  Vec2D startPos;
public:
  void update() override;
};

class TempPlatform : public Platform 
{
public:
  void update() override;
};

class HTelePlatform : public Platform
{
  Vec2D startPos;
public:
    void update() override;
};

class VTelePlatform : public Platform
{
  Vec2D startPos;
public:
    void update() override;
};

#endif //PLATFORM_H
