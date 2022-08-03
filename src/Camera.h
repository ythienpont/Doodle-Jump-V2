#ifndef CAMERA_H
#define CAMERA_H

#include "Vec2D.h"

const int SCREENW = 480;
const int SCREENH = 700;
namespace Logic
{
  class Camera 
  {
    double baseHeight;
  public:
    Camera();

    Vec2D toPixelCoordinates(const Vec2D& pos);
  };
}
#endif //CAMERA_H
