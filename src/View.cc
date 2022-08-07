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
  /*
  sf::Texture texture;
  texture.loadFromFile(texturePath);
  setTexture(texture); 
  */
}

void Representation::View::update(const Vec2D& position)
{
  setPosition(Vec2DToVector2f(position));
}

Representation::Player::Player(const Vec2D& position) : View(position)
{
  //applyTexture(PLAYERTEXTUREFILE);
  //scale(0.2, 0.2);
  setFillColor(sf::Color::Cyan);
  setSize(sf::Vector2f(44,-71));
}

Representation::Platform::Platform(const Vec2D& position) : View(position)
{
  //applyTexture(PLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Green);
  setSize(sf::Vector2f(64,-16));
}

Representation::HPlatform::HPlatform(const Vec2D& position) : View(position)
{
  //applyTexture(HPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Blue);
  setSize(sf::Vector2f(64,-16));
}

Representation::VPlatform::VPlatform(const Vec2D& position) : View(position)
{
  //applyTexture(VPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Yellow);
  setSize(sf::Vector2f(64,-16));
}

Representation::TempPlatform::TempPlatform(const Vec2D& position) : View(position)
{
  //applyTexture(TEMPPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::White);
  setSize(sf::Vector2f(64,-16));
}

Representation::Enemy::Enemy(const Vec2D& position) : View(position)
{
  //applyTexture(TEMPPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Red);
  setSize(sf::Vector2f(20,-20));
}

Representation::PlayerBullet::PlayerBullet(const Vec2D& position) : View(position)
{
  //applyTexture(TEMPPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Blue);
  setSize(sf::Vector2f(3,-10));
}
