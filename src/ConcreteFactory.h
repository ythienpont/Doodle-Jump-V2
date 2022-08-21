#ifndef CONCRETE_FACTORY_H
#define CONCRETE_FACTORY_H

#include "../lib/include/AbstractFactory.h"
#include "View.h"
#include <SFML/Graphics.hpp>
class ConcreteFactory : public AbstractFactory
{
public:
  std::unique_ptr<Logic::Player> createPlayer(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::Platform> createPlatform(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::HPlatform> createHPlatform(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::HTelePlatform> createHTelePlatform(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::VPlatform> createVPlatform(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::VTelePlatform> createVTelePlatform(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::TempPlatform> createTempPlatform(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::Enemy> createEnemy(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::ShootingEnemy> createShootingEnemy(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::PlayerBullet> createPlayerBullet(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::EnemyBullet> createEnemyBullet(const Vec2D& pos, const Vec2D& pixelPos, const Vec2D& velocity) const override;
  std::shared_ptr<Logic::Spikes> createSpikes(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::shared_ptr<Logic::Spring> createSpring(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::shared_ptr<Logic::Heart> createHeart(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::shared_ptr<Logic::Jetpack> createJetpack(const Vec2D& pos, const Vec2D& pixelPos) const override;
  std::unique_ptr<Logic::Effect> createEnemyHitEffect() const override;
  std::unique_ptr<Logic::Effect> createFriendlyHitEffect() const override;
  std::unique_ptr<Logic::BGTile> createBGTile(const Vec2D& pos, const Vec2D& pixelPos) const override;
};

#endif //CONCRETE_FACTORY_H
