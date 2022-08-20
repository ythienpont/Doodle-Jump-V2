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

Representation::HTelePlatform::HTelePlatform(const Vec2D& position) : View(position)
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

Representation::VTelePlatform::VTelePlatform(const Vec2D& position) : View(position)
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
  setSize(sf::Vector2f(30,-30));
}

Representation::ShootingEnemy::ShootingEnemy(const Vec2D& position) : View(position)
{
  //applyTexture(TEMPPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Red);
  setSize(sf::Vector2f(40,-40));
}

Representation::PlayerBullet::PlayerBullet(const Vec2D& position) : View(position)
{
  //applyTexture(TEMPPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Cyan);
  setSize(sf::Vector2f(5,-20));
}

Representation::EnemyBullet::EnemyBullet(const Vec2D& position) : View(position)
{
  //applyTexture(TEMPPLATFORMTEXTUREFILE);
  setFillColor(sf::Color::Red);
  setSize(sf::Vector2f(5,-20));
}

Representation::Spikes::Spikes(const Vec2D& position) : View(position)
{
  setFillColor(sf::Color::Red);
  setSize(sf::Vector2f(64,-4));
}

Representation::Spring::Spring(const Vec2D& position) : View(position)
{
  setFillColor(sf::Color(190, 190, 190));
  setSize(sf::Vector2f(20,-20));
}

Representation::Heart::Heart(const Vec2D& position) : View(position)
{
  setFillColor(sf::Color::Green);
  setSize(sf::Vector2f(20,-20));
}

Representation::Jetpack::Jetpack(const Vec2D& position) : View(position)
{
  setFillColor(sf::Color(190, 190, 190));
  setSize(sf::Vector2f(16,-40));
}

Representation::BGTile::BGTile(const Vec2D& position) : View(position)
{
  setOutlineColor(sf::Color(255,255,255,64));
  setOutlineThickness(1);
  //setFillColor(sf::Color::Black);
  setFillColor(sf::Color(0,0,0,0));
  setSize(sf::Vector2f(80,-160));
}

Representation::Effect::Effect(const bool friendly) : View(Vec2D(0,0))
{
  if (friendly)
  {
    setFillColor(sf::Color::Red);
  }
  else
  {
    setFillColor(sf::Color::White);
  }
  setSize(sf::Vector2f(SCREENW,SCREENH));
}
