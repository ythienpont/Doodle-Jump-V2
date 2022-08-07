#include "Model.h"

Logic::Model::Model(const Vec2D& startPos, const double& w, const double& h) : pos(startPos), col(Collider(w, h))
{

}

Logic::Model::Model(const double& w, const double& h) : Model(Vec2D(0,0),w,h)
{

}

void Logic::Model::setPosition(const double& x, const double& y)
{
  pos.x = x;
  pos.y = y;
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
  view->update(Camera::getInstance()->toPixelCoordinates(pos));
}