#ifndef CAMERA_H
#define CAMERA_H

#include "Vec2D.h"
#include <math.h>

const int SCREENW = 480;
//const int SCREENH = 700;
const int SCREENH = 900;
namespace Logic
{
  class Camera
  {
  private:
    static Camera* instance;
    Camera();
    double baseHeight;
  public:
    static Camera* getInstance();

    Vec2D toPixelCoordinates(const Vec2D& pos) const;

    bool isOutOfUpperBounds(const Vec2D& pos) const;
    bool isOutOfLowerBounds(const Vec2D& pos) const;

    int updateBaseHeight(const Vec2D& playerPos, const double& playerVel);
  };
}
#endif //CAMERA_H
