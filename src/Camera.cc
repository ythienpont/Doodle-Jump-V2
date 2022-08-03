#include "Camera.h"

Logic::Camera::Camera() : baseHeight(0) { }

Vec2D Logic::Camera::toPixelCoordinates(const Vec2D& pos)
{
  return Vec2D(pos.x, SCREENH-(pos.y-baseHeight));
}
