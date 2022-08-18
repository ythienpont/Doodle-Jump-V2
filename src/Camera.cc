#include "Camera.h"

Logic::Camera::Camera() : baseHeight(0) { }

Logic::Camera* Logic::Camera::getInstance()
{
  if (!instance) instance = new Camera;

  return instance;
}

Vec2D Logic::Camera::toPixelCoordinates(const Vec2D& pos) const
{
  return Vec2D(pos.x, SCREENH-(pos.y-baseHeight));
}

int Logic::Camera::updateBaseHeight(const Vec2D& playerPos, const double& playerVel)
{
  if (playerPos.y >= baseHeight + 2*((double) SCREENH/3))
  {
    baseHeight += playerVel;
    return std::round(playerVel);
  }

  return 0;
}

bool Logic::Camera::isOutOfLowerBounds(const Vec2D& pos) const
{
  return pos.y <= baseHeight;
}

bool Logic::Camera::isOutOfUpperBounds(const Vec2D& pos) const
{
  return pos.y >= baseHeight+SCREENH;
}
