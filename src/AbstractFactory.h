#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "Vec2D.h"
#include <SFML/Graphics.hpp>
#include "Model.h"
#include "View.h"
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "Bonus.h"
#include "BGTile.h"
#include "Projectile.h"
#include "Effect.h"

class AbstractFactory
{
public:
  virtual std::unique_ptr<Logic::Player> createPlayer(const Vec2D& pos) const=0 ;
  virtual std::unique_ptr<Logic::Platform> createPlatform(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::HPlatform> createHPlatform(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::HTelePlatform> createHTelePlatform(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::VPlatform> createVPlatform(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::VTelePlatform> createVTelePlatform(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::TempPlatform> createTempPlatform(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::BGTile> createTile(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::Enemy> createEnemy(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::ShootingEnemy> createShootingEnemy(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::PlayerBullet> createPlayerBullet(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::EnemyBullet> createEnemyBullet(const Vec2D& pos) const=0;
  virtual std::shared_ptr<Logic::Spikes> createSpikes(const Vec2D& pos) const=0;
  virtual std::shared_ptr<Logic::Spring> createSpring(const Vec2D& pos) const=0;
  virtual std::shared_ptr<Logic::Heart> createHeart(const Vec2D& pos) const=0;
  virtual std::shared_ptr<Logic::Jetpack> createJetpack(const Vec2D& pos) const=0;
  virtual std::unique_ptr<Logic::Effect> createEnemyHitEffect() const=0;
  virtual std::unique_ptr<Logic::Effect> createFriendlyHitEffect() const=0;
  virtual std::unique_ptr<Logic::BGTile> createBGTile(const Vec2D& pos) const=0;
};

class ConcreteFactory : public AbstractFactory
{
public:
  std::unique_ptr<Logic::Player> createPlayer(const Vec2D& pos) const override;
  std::unique_ptr<Logic::Platform> createPlatform(const Vec2D& pos) const override;
  std::unique_ptr<Logic::HPlatform> createHPlatform(const Vec2D& pos) const override;
  std::unique_ptr<Logic::HTelePlatform> createHTelePlatform(const Vec2D& pos) const override;
  std::unique_ptr<Logic::VPlatform> createVPlatform(const Vec2D& pos) const override;
  std::unique_ptr<Logic::VTelePlatform> createVTelePlatform(const Vec2D& pos) const override;
  std::unique_ptr<Logic::TempPlatform> createTempPlatform(const Vec2D& pos) const override;
  std::unique_ptr<Logic::BGTile> createTile(const Vec2D& pos) const override;
  std::unique_ptr<Logic::Enemy> createEnemy(const Vec2D& pos) const override;
  std::unique_ptr<Logic::ShootingEnemy> createShootingEnemy(const Vec2D& pos) const override;
  std::unique_ptr<Logic::PlayerBullet> createPlayerBullet(const Vec2D& pos) const override;
  std::unique_ptr<Logic::EnemyBullet> createEnemyBullet(const Vec2D& pos) const override;
  std::shared_ptr<Logic::Spikes> createSpikes(const Vec2D& pos) const override;
  std::shared_ptr<Logic::Spring> createSpring(const Vec2D& pos) const override;
  std::shared_ptr<Logic::Heart> createHeart(const Vec2D& pos) const override;
  std::shared_ptr<Logic::Jetpack> createJetpack(const Vec2D& pos) const override;
  std::unique_ptr<Logic::Effect> createEnemyHitEffect() const override;
  std::unique_ptr<Logic::Effect> createFriendlyHitEffect() const override;
  std::unique_ptr<Logic::BGTile> createBGTile(const Vec2D& pos) const override;
};

#endif //ABSTRACTFACTORY_H
