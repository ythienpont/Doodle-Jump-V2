#include "Model.h"

Logic::Model::Model(const Vec2D& startPos, const double& w, const double& h, const int scoreD) : pos(startPos), pixelPos(0,0), col(Collider(w, h)), scoreDelta(scoreD)
{

}

Logic::Model::Model(const double& w, const double& h, const int scoreD) : Model(Vec2D(0,0),w,h, scoreD)
{

}

void Logic::Model::setPosition(const double& x, const double& y)
{
  pos.x = x;
  pos.y = y;
}

void Logic::Model::setPixelPos(const Vec2D& pPos)
{
  pixelPos = pPos;
}

void Logic::Model::setPosition(const Vec2D& newPos)
{
  pos = newPos;
}

Vec2D Logic::Model::getPosition() const
{
  return pos;
}

void Logic::Model::move(const Vec2D& velocity)
{
  pos += velocity;
}

bool Logic::Model::collidesWith(const Model& e)
{
  if (pos.x + col.width >= e.pos.x &&
      pos.x <= e.pos.x + e.col.width &&
      pos.y + col.height >= e.pos.y &&
      pos.y <= e.pos.y + e.col.height)
  {
    return true;
  }

  return false;
}

Logic::Moving::Moving(const Vec2D& vel) : velocity(vel)
{
}

void Logic::Moving::setVelocity(const Vec2D& vel)
{
  velocity = vel;
}

Vec2D Logic::Moving::getVelocity() const
{
  return velocity;
}

void Logic::Moving::addVelocity(const Vec2D& vel)
{
  velocity += vel;
}

void Logic::Model::registerObserver(std::shared_ptr<Representation::View> observer)
{
  view = observer;
}

void Logic::Model::removeObserver(std::shared_ptr<Representation::View> observer)
{
  view = nullptr;
}

void Logic::Model::notifyObservers()
{
  view->update(pixelPos);
}

void Logic::Model::moveOutOfBounds()
{
  move(Vec2D(0, -10000));
}

Logic::Living::Living(const int points) : hp(points) { }

bool Logic::Living::isDead() const
{
  return hp <= 0;
}

void Logic::Living::addHP(const int points)
{
  hp += points;
}

void Logic::Living::setHP(const int points)
{
  hp = points;
}

int Logic::Living::getHP() const
{
  return hp;
}

void Logic::Living::kill()
{
  hp = 0;
}

Logic::Jumpable::Jumpable() : jumpedOn(false) { }

bool Logic::Jumpable::hasBeenJumpedOn() const
{
  return jumpedOn;
}

void Logic::Jumpable::resetJumpedOn()
{
  jumpedOn = false;
}

void Logic::Jumpable::jumpOn()
{
  jumpedOn = true;
}

void Logic::Living::hit()
{
  hp -= 1;
}

int Logic::Model::getScoreDelta() const
{
  return scoreDelta;
}

Logic::Model::~Model()
{
  view = nullptr;
}

bool Logic::Model::isInRange(const Vec2D& ePos, const int range) const
{
  int distance = std::sqrt(std::pow(pos.x-ePos.x,2) + std::pow(pos.y-ePos.y,2));

  return distance <= range;
}

Vec2D Logic::Model::pathToObject(const Vec2D& ePos) const
{
  return Vec2D(ePos.x-pos.x,ePos.y-pos.y);
}
