#ifndef CAMERA_H
#define CAMERA_H

#include "Vec2D.h"
#include <math.h>

const int SCREENW = 470;
const int SCREENH = 900;

namespace Logic
{
  class Camera
  {
  private:
    double baseHeight;
  public:
    Camera();

    Vec2D toPixelCoordinates(const Vec2D& pos) const;

    bool isOutOfUpperBounds(const Vec2D& pos) const;
    bool isOutOfBounds(const Vec2D& pos) const;
    bool isOutOfLowerBounds(const Vec2D& pos) const;
    bool isOutOfLowerBounds(const Vec2D& pos, const double& delta) const;

    int updateBaseHeight(const Vec2D& playerPos, const double& playerVel);
  };
}
#endif //CAMERA_H
