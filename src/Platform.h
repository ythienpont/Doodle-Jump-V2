#ifndef PLATFORM_H
#define PLATFORM_H

#include "Model.h"
#include "Random.h"

const int VRANGE = 100;
const int HRANGE = 200;
const double PWIDTH = 64;
const double PHEIGHT = 16;
const int PLATDELTA = -500;
const int HPLATDELTA = -300;
const int VPLATDELTA = -400;
const int TELEDELTA = 0; // Score delta for TempPlatform and HTelePlatform

namespace Logic
{
  class Platform : public Model , public Jumpable
  {
    bool jumpedOn;
  public:
    explicit Platform(const Vec2D& startPos);
    int getCredits() const;
    virtual void update() override;
  protected:
    Platform(const Vec2D& pos, const int scoreD);
  };

  class HPlatform : public Platform, public Moving
  {
  public:
    explicit HPlatform(const Vec2D& pos);
    void update() override;
  };

  class VPlatform : public Platform, public Moving
  {
    Vec2D startPos;
  public:
    explicit VPlatform(const Vec2D& pos);
    void update() override;
  };

  class TempPlatform : public Platform
  {
  public:
    explicit TempPlatform(const Vec2D& pos);
    void jumpOn() override;
  };

  class HTelePlatform : public Platform
  {
    Vec2D startPos;
  public:
    explicit HTelePlatform(const Vec2D& pos);
    void jumpOn() override;
  };

  class VTelePlatform : public Platform
  {
    Vec2D startPos;
  public:
    explicit VTelePlatform(const Vec2D& pos);
    void jumpOn() override;
  };
}
#endif //PLATFORM_H
