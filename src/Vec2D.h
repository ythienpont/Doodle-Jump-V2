#ifndef VEC2D_H
#define VEC2D_H

struct Vec2D
{
  double x;
  double y;
  Vec2D(const double& xx, const double& yy);

  Vec2D operator+(const Vec2D& that);
  Vec2D operator-(const Vec2D& that);
  void operator+=(const Vec2D& that);
  void operator-=(const Vec2D& that);
};

#endif //VEC2D_H
