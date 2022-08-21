#ifndef BONUS_H
#define BONUS_H

#include "Model.h"

const int BONUS_AMT = 4;
const int GOOD_DELTA = 500;
const int BAD_DELTA = -500;
const int BONUS_WIDTH = 20;

namespace Logic
{
  class Bonus : public Model, public Jumpable
  {
  private:
    double distance;
    double jumpMultiplier;
    double velocity;
    int health;
  public:
    virtual void update();
    double getDistance() const;
    double getJumpMultiplier() const;
    double getVelocity() const;
    int getHealth() const;
    void decreaseDistance(const double& dist);
    bool isDone() const;
  protected:
    Bonus(const Vec2D& pos, const double& w, const double& h, const double& d, const double& jm, const double& vel, const int hp, const int scoreD);
  };

  class Spikes : public Bonus
  {
  public:
    Spikes(const Vec2D& pos);
  };

  class Spring : public Bonus
  {
  public:
    Spring(const Vec2D& pos);
  };

  class Heart : public Bonus
  {
  public:
    Heart(const Vec2D& pos);
    void jumpOn() override;
  };

  class Jetpack : public Bonus
  {
  public:
    Jetpack(const Vec2D& pos);
  };
}

#endif //BONUS_H
