#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
  double x;
  double y;
  Vec2D(const double& newX, const double& newY);

  Vec2D operator+(const Vec2D& that);
  Vec2D operator-(const Vec2D& that);
  void operator+=(const Vec2D& that);
  void operator-=(const Vec2D& that);
};

#endif //VEC2D_H
