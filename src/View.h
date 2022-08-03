#ifndef VIEW_H
#define VIEW_H 

#include "Observer.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

const std::string PLAYERTEXTUREFILE = "images/player.png";
const std::string PLATFORMTEXTUREFILE = "images/static_platform.png";
const std::string HPLATFORMTEXTUREFILE = "images/horizontal_platform.png";
const std::string VPLATFORMTEXTUREFILE = "images/vertical_platform.png";
const std::string TEMPPLATFORMTEXTUREFILE = "images/temporary_platform.png";

namespace Representation
{
  class View : public Observer, public sf::Sprite, public Entity
  {
  public:
    View(const Vec2D& position);

    void applyTexture(const std::string& texturePath);
    // Observer code
    void update(const Vec2D& position) override { }
  };

  class Player : public View
  {
  public:
    Player(const Vec2D& position);
  };

  class Platform : public View
  {
  public:
    Platform(const Vec2D& position);
  };

  class HPlatform : public View
  {
    HPlatform(const Vec2D& position);
  };

  class VPlatform : public View
  {
    VPlatform(const Vec2D& position);
  };

  class TempPlatform : public View
  {

    TempPlatform(const Vec2D& position);
  };

  class HTelePlatform : public View
  {
    HTelePlatform(const Vec2D& position);
  };

  class VTelePlatform : public View
  {
    VTelePlatform(const Vec2D& position);
  };

  class BGTile : public View 
  {

  };

  class Spring : public View
  {

  };

  class Jetpack : public View
  {

  };

  class PlayerBullet : public View
  {

  };

  class EnemyBullet : public View
  {

  };
}

#endif //VIEW_H
