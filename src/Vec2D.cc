#include "Vec2D.h"

Vec2D::Vec2D(const double& xx, const double& yy)
{
  x = xx;
  y = yy;
}

double Vec2D::length() const
{
  return std::sqrt(std::pow(x,2)+std::pow(y,2));
}

void Vec2D::normalize()
{
  double l = length();
  x/=l;
  y/=l;
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

void Vec2D::operator*=(const double& n)
{
  x*=n;
  y*=n;
}

void Vec2D::operator/=(const double& n)
{
  x/=n;
  y/=n;
}
