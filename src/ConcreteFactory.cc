#include "ConcreteFactory.h"
#include <iostream>
std::unique_ptr<Logic::Player> ConcreteFactory::createPlayer(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::Player> playerModel = std::make_unique<Logic::Player>(pos);
  std::shared_ptr<Representation::Player> playerView = std::make_shared<Representation::Player>(pixelPos);
  playerModel->registerObserver(playerView);

  return playerModel;

};

std::unique_ptr<Logic::Platform> ConcreteFactory::createPlatform(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::Platform> platformModel = std::make_unique<Logic::Platform>(pos);
  std::shared_ptr<Representation::Platform> platformView = std::make_shared<Representation::Platform>(pixelPos);
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::TempPlatform> ConcreteFactory::createTempPlatform(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::TempPlatform> platformModel = std::make_unique<Logic::TempPlatform>(pos);
  std::shared_ptr<Representation::TempPlatform> platformView = std::make_shared<Representation::TempPlatform>(pixelPos);
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::HPlatform> ConcreteFactory::createHPlatform(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::HPlatform> platformModel = std::make_unique<Logic::HPlatform>(pos);
  std::shared_ptr<Representation::HPlatform> platformView = std::make_shared<Representation::HPlatform>(pixelPos);
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::HTelePlatform> ConcreteFactory::createHTelePlatform(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::HTelePlatform> platformModel = std::make_unique<Logic::HTelePlatform>(pos);
  std::shared_ptr<Representation::HTelePlatform> platformView = std::make_shared<Representation::HTelePlatform>(pixelPos);
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::VPlatform> ConcreteFactory::createVPlatform(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::VPlatform> platformModel = std::make_unique<Logic::VPlatform>(pos);
  std::shared_ptr<Representation::VPlatform> platformView = std::make_shared<Representation::VPlatform>(pixelPos);
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::VTelePlatform> ConcreteFactory::createVTelePlatform(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::VTelePlatform> platformModel = std::make_unique<Logic::VTelePlatform>(pos);
  std::shared_ptr<Representation::VTelePlatform> platformView = std::make_shared<Representation::VTelePlatform>(pixelPos);
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::Enemy> ConcreteFactory::createEnemy(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::Enemy> enemyModel = std::make_unique<Logic::Enemy>(pos);
  std::shared_ptr<Representation::Enemy> enemyView = std::make_shared<Representation::Enemy>(pixelPos);
  enemyModel->registerObserver(enemyView);

  return enemyModel;
};

std::unique_ptr<Logic::ShootingEnemy> ConcreteFactory::createShootingEnemy(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::ShootingEnemy> enemyModel = std::make_unique<Logic::ShootingEnemy>(pos);
  std::shared_ptr<Representation::ShootingEnemy> enemyView = std::make_shared<Representation::ShootingEnemy>(pixelPos);
  enemyModel->registerObserver(enemyView);

  return enemyModel;
};

std::unique_ptr<Logic::PlayerBullet> ConcreteFactory::createPlayerBullet(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::PlayerBullet> bulletModel = std::make_unique<Logic::PlayerBullet>(pos);
  std::shared_ptr<Representation::PlayerBullet> bulletView = std::make_shared<Representation::PlayerBullet>(pixelPos);
  bulletModel->registerObserver(bulletView);

  return bulletModel;
};

std::unique_ptr<Logic::EnemyBullet> ConcreteFactory::createEnemyBullet(const Vec2D& pos, const Vec2D& pixelPos, const Vec2D& velocity) const
{
  std::unique_ptr<Logic::EnemyBullet> bulletModel = std::make_unique<Logic::EnemyBullet>(pos, velocity);
  std::shared_ptr<Representation::EnemyBullet> bulletView = std::make_shared<Representation::EnemyBullet>(pixelPos);
  bulletModel->registerObserver(bulletView);

  return bulletModel;
};

std::unique_ptr<Logic::BGTile> ConcreteFactory::createBGTile(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::unique_ptr<Logic::BGTile> tileModel = std::make_unique<Logic::BGTile>(pos);
  std::shared_ptr<Representation::BGTile> tileView = std::make_shared<Representation::BGTile>(pixelPos);
  tileModel->registerObserver(tileView);

  return tileModel;
};

std::shared_ptr<Logic::Spikes> ConcreteFactory::createSpikes(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::shared_ptr<Logic::Spikes> bonusModel = std::make_shared<Logic::Spikes>(pos);
  std::shared_ptr<Representation::Spikes> bonusView = std::make_shared<Representation::Spikes>(pixelPos);
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};

std::shared_ptr<Logic::Spring> ConcreteFactory::createSpring(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::shared_ptr<Logic::Spring> bonusModel = std::make_shared<Logic::Spring>(pos);
  std::shared_ptr<Representation::Spring> bonusView = std::make_shared<Representation::Spring>(pixelPos);
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};

std::shared_ptr<Logic::Heart> ConcreteFactory::createHeart(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::shared_ptr<Logic::Heart> bonusModel = std::make_shared<Logic::Heart>(pos);
  std::shared_ptr<Representation::Heart> bonusView = std::make_shared<Representation::Heart>(pixelPos);
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};

std::shared_ptr<Logic::Jetpack> ConcreteFactory::createJetpack(const Vec2D& pos, const Vec2D& pixelPos) const
{
  std::shared_ptr<Logic::Jetpack> bonusModel = std::make_shared<Logic::Jetpack>(pos);
  std::shared_ptr<Representation::Jetpack> bonusView = std::make_shared<Representation::Jetpack>(pixelPos);
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};

std::unique_ptr<Logic::Effect> ConcreteFactory::createEnemyHitEffect() const
{
  std::unique_ptr<Logic::Effect> effectModel = std::make_unique<Logic::Effect>();
  std::shared_ptr<Representation::Effect> effectView = std::make_shared<Representation::Effect>(false);
  effectModel->registerObserver(effectView);

  return effectModel;
}

std::unique_ptr<Logic::Effect> ConcreteFactory::createFriendlyHitEffect() const
{
  std::unique_ptr<Logic::Effect> effectModel = std::make_unique<Logic::Effect>();
  std::shared_ptr<Representation::Effect> effectView = std::make_shared<Representation::Effect>(true);
  effectModel->registerObserver(effectView);

  return effectModel;
}
