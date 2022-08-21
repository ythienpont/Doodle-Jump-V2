#ifndef VEC2D_H
#define VEC2D_H

#include <math.h>

struct Vec2D
{
  double x;
  double y;
  Vec2D(const double& xx, const double& yy);

  double length() const;
  void normalize();

  Vec2D operator+(const Vec2D& that);
  Vec2D operator-(const Vec2D& that);
  void operator+=(const Vec2D& that);
  void operator-=(const Vec2D& that);
  Vec2D operator*(const Vec2D& that);
  void operator*=(const double& n);
  void operator/=(const double& n);
};

#endif //VEC2D_H
