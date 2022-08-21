#include "../include/Bonus.h"

// OOP in a nutshell...

Logic::Bonus::Bonus(const Vec2D& pos, const double& w, const double& h, const double& d, const double& jm, const double& vel, const int hp, const int scoreD) : Model(pos, w, h, scoreD), Jumpable(), distance(d), jumpMultiplier(jm), velocity(vel), health(hp) { }

Logic::Spikes::Spikes(const Vec2D& pos) : Bonus(pos, 64, 4, 0, 1, 0, -1, BAD_DELTA) { } // Force a jump

Logic::Spring::Spring(const Vec2D& pos) : Bonus(pos, 20, 20, 0, 4, 0, 0, GOOD_DELTA) { }

Logic::Heart::Heart(const Vec2D& pos) : Bonus(pos, 20, 20, 0, 0, 0, 1, GOOD_DELTA) { }

Logic::Jetpack::Jetpack(const Vec2D& pos) : Bonus(pos, 16, 40, 9000, 0, 40, 0, GOOD_DELTA) { }

void Logic::Bonus::update()
{
  notifyObservers();
}

double Logic::Bonus::getDistance() const
{
  return distance;
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

void Logic::Bonus::decreaseDistance(const double& dist)
{
  distance -= dist;
}

bool Logic::Bonus::isDone() const
{
  return distance <= 0;
}

void Logic::Heart::jumpOn()
{
  moveOutOfBounds();
}
