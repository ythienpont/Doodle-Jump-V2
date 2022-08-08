#include "Bonus.h"

// OOP in a nutshell...

Logic::Bonus::Bonus(const Vec2D& pos, const double& w, const double& h, const double& d, const double& jm, const double& vel, const int hp) : Model(pos, w, h), Jumpable(), duration(d), jumpMultiplier(jm), velocity(vel), health(hp) { }

Logic::Spikes::Spikes(const Vec2D& pos) : Bonus(pos, 64, 4, 0, 1, 0, -1) { } // Force a jump

Logic::Spring::Spring(const Vec2D& pos) : Bonus(pos, 20, 20, 0, 4, 0, 0) { }

Logic::Heart::Heart(const Vec2D& pos) : Bonus(pos, 20, 20, 0, 0, 0, 1) { }

Logic::Jetpack::Jetpack(const Vec2D& pos) : Bonus(pos, 16, 40, 4, 0, 40, 0) { }

void Logic::Bonus::update()
{
  notifyObservers();
}

double Logic::Bonus::getDuration() const
{
  return duration;
}

double Logic::Bonus::getJumpMultiplier() const
{
  return jumpMultiplier;
}

double Logic::Bonus::getVelocity() const
{
  return velocity;
}

int Logic::Bonus::getHealth() const
{
  return health;
}

void Logic::Bonus::decreaseDuration(const double& time)
{
  duration -= time;
}

bool Logic::Bonus::isDone() const
{
  return duration <= 0;
}

void Logic::Heart::update()
{
  moveOutOfBounds();
  notifyObservers();
}
