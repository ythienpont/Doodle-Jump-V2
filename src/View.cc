#include "View.h"

sf::Vector2f Vec2DToVector2f(const Vec2D& v)
{
  return sf::Vector2f(v.x, v.y);
}

Representation::View::View(const Vec2D& position)
{
  setPosition(Vec2DToVector2f(position));
}

void Representation::View::applyTexture(const std::string& texturePath)
{
  sf::Texture texture;
  texture.loadFromFile(texturePath);
  setTexture(texture); 
}

Representation::Player::Player(const Vec2D& position) : View(position)
{
  applyTexture(PLAYERTEXTUREFILE);
  scale(0.2, 0.2);
}

Representation::Platform::Platform(const Vec2D& position) : View(position)
{
  applyTexture(PLATFORMTEXTUREFILE);
}

Representation::HPlatform::HPlatform(const Vec2D& position) : View(position)
{
  applyTexture(HPLATFORMTEXTUREFILE);
}

Representation::VPlatform::VPlatform(const Vec2D& position) : View(position)
{
  applyTexture(VPLATFORMTEXTUREFILE);
}

Representation::TempPlatform::TempPlatform(const Vec2D& position) : View(position)
{
  applyTexture(TEMPPLATFORMTEXTUREFILE);
}
