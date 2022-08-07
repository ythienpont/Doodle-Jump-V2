#ifndef PLATFORM_H
#define PLATFORM_H

#include "Model.h"
#include "Random.h"

const int VRANGE = 100;
const int HRANGE = 20;
const double PWIDTH = 64;
const double PHEIGHT = 16;

namespace Logic
{
  class Platform : public Model
  {
    bool jumpedOn;
    int credits; // Used for controlling difficulty
  public:
    Platform(const Vec2D& startPos);
    virtual void update() override;
    bool hasBeenJumpedOn() const;
    void jumpOn();
    int getCredits() const;
  protected:
    Platform(const Vec2D& pos, const int creds);
  };

  class HPlatform : public Platform, public Moving
  {
  public:
    HPlatform(const Vec2D& pos);
    void update() override;
  };

  class VPlatform : public Platform, public Moving
  {
    Vec2D startPos;
  public:
    VPlatform(const Vec2D& pos);
    void update() override;
  };

  class TempPlatform : public Platform 
  {
  public:
    TempPlatform(const Vec2D& pos);
    void update() override;
  };

  class HTelePlatform : public Platform
  {
    Vec2D startPos;
  public:
    HTelePlatform(const Vec2D& pos);
    void update() override;
  };

  class VTelePlatform : public Platform
  {
    Vec2D startPos;
  public:
    VTelePlatform(const Vec2D& pos);
    void update() override;
  };
}
#endif //PLATFORM_H
