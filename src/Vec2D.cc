#include "Vec2D.h"

Vec2D::Vec2D(const double& newX, const double& newY)
{
  x = newX;
  y = newY;
}

Vec2D Vec2D::operator+(const Vec2D& that)
{
  return Vec2D(this->x+that.x, this->y+that.y);
}

Vec2D Vec2D::operator-(const Vec2D& that)
{
  return Vec2D(this->x-that.x, this->y-that.y);
}

void Vec2D::operator+=(const Vec2D& that)
{
  this->x+=that.x;
  this->y+=that.y;
}

void Vec2D::operator-=(const Vec2D& that)
{
  this->x-=that.x;
  this->y-=that.y;
}
