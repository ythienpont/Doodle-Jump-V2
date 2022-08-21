#ifndef VIEW_H
#define VIEW_H

#include "../lib/include/Observer.h"
#include <SFML/Graphics.hpp>
#include "../lib/include/Camera.h"

namespace Representation
{
  class View : public Logic::Observer, public sf::RectangleShape
  {
  public:
    View(const Vec2D& position);

    // Observer code
    void update(const Vec2D& position) override;
  };

  class Player : public View
  {
  public:
    explicit Player(const Vec2D& position);
  };

  class Platform : public View
  {
  public:
    explicit Platform(const Vec2D& position);
  };

  class HPlatform : public View
  {
  public:
    explicit HPlatform(const Vec2D& position);
  };

  class VPlatform : public View
  {
  public:
    explicit VPlatform(const Vec2D& position);
  };

  class TempPlatform : public View
  {
  public:
    explicit TempPlatform(const Vec2D& position);
  };

  class HTelePlatform : public View
  {
  public:
    explicit HTelePlatform(const Vec2D& position);
  };

  class VTelePlatform : public View
  {
  public:
    explicit VTelePlatform(const Vec2D& position);
  };

  class Enemy : public View
  {
  public:
    explicit Enemy(const Vec2D& position);
  };

  class ShootingEnemy : public View
  {
  public:
    explicit ShootingEnemy(const Vec2D& position);
  };


  class BGTile : public View
  {
  public:
    explicit BGTile(const Vec2D& position);
  };

  class Spring : public View
  {
  public:
    explicit Spring(const Vec2D& position);
  };

  class Jetpack : public View
  {
  public:
    explicit Jetpack(const Vec2D& position);
  };

  class Heart : public View
  {
  public:
    explicit Heart(const Vec2D& position);
  };

  class Spikes : public View
  {
  public:
    explicit Spikes(const Vec2D& position);
  };

  class PlayerBullet : public View
  {
  public:
    explicit PlayerBullet(const Vec2D& position);
  };

  class EnemyBullet : public View
  {
  public:
    explicit EnemyBullet(const Vec2D& position);
  };

  class Effect : public View
  {
  public:
    explicit Effect(const bool friendly);
  };
}

#endif //VIEW_H
