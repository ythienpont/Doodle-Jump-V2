#ifndef CAMERA_H
#define CAMERA_H

#include "Vec2D.h"

class Camera 
{
  Vec2D toPixelCoordinates(const Vec2D& orig);
};

#endif //CAMERA_H
