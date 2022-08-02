#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include "Vec2D.h"
#include "Collider.h"

class Moving
{
  Vec2D velocity;
public:
  Moving(const Vec2D& vel);
  Vec2D getVelocity() const;
  void setVelocity(const Vec2D& vel);
  void addVelocity(const Vec2D& vel);
};

class Entity 
{
public:
  Vec2D pos;

  Entity(const double& w, const double& h);
  Entity(const Vec2D& startPos, const double& w, const double& h);

  Collider col;

  virtual void update()=0;

  void setPosition(const double& x, const double& y);
  void setPosition(const Vec2D& newPos);
  Vec2D getPosition() const;
  
  void move(const Vec2D& velocity);

  bool collidesWith(const Entity& e);
};

#endif //ENTITY_H
