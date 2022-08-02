#include "Entity.h"

Entity::Entity(const Vec2D& startPos, const double& w, const double& h) : pos(startPos), col(Collider(w, h))
{

}

Entity::Entity(const double& w, const double& h) : Entity(Vec2D(0,0),w,h)
{

}

void Entity::setPosition(const double& x, const double& y)
{
  pos.x = x;
  pos.y = y;
}

void Entity::setPosition(const Vec2D& newPos)
{
  pos = newPos;
}

Vec2D Entity::getPosition() const
{
  return pos;
}

void Entity::move(const Vec2D& velocity)
{
  pos += velocity;
}

bool Entity::collidesWith(const Entity& e)
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

Moving::Moving(const Vec2D& vel) : velocity(vel)
{
}

void Moving::setVelocity(const Vec2D& vel)
{
  velocity = vel;
}

Vec2D Moving::getVelocity() const 
{
  return velocity;
}

void Moving::addVelocity(const Vec2D& vel)
{
  velocity += vel;
}
