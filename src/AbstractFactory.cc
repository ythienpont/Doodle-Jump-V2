#include "AbstractFactory.h"

std::unique_ptr<Logic::Player> ConcreteFactory::createPlayer(const Vec2D& pos)
{
  std::unique_ptr<Logic::Player> playerModel = std::make_unique<Logic::Player>(pos);
  std::shared_ptr<Representation::Player> playerView = std::make_shared<Representation::Player>(pos);
  playerModel->registerObserver(playerView);

  return playerModel;
  
};

std::unique_ptr<Logic::Platform> ConcreteFactory::createPlatform(const Vec2D& pos)
{
  std::unique_ptr<Logic::Platform> platformModel = std::make_unique<Logic::Platform>(pos);
  std::shared_ptr<Representation::Platform> platformView = std::make_shared<Representation::Platform>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::TempPlatform> ConcreteFactory::createTempPlatform(const Vec2D& pos)
{
  std::unique_ptr<Logic::TempPlatform> platformModel = std::make_unique<Logic::TempPlatform>(pos);
  std::shared_ptr<Representation::TempPlatform> platformView = std::make_shared<Representation::TempPlatform>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::HPlatform> ConcreteFactory::createHPlatform(const Vec2D& pos)
{
  std::unique_ptr<Logic::HPlatform> platformModel = std::make_unique<Logic::HPlatform>(pos);
  std::shared_ptr<Representation::HPlatform> platformView = std::make_shared<Representation::HPlatform>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::HTelePlatform> ConcreteFactory::createHTelePlatform(const Vec2D& pos)
{
  std::unique_ptr<Logic::HTelePlatform> platformModel = std::make_unique<Logic::HTelePlatform>(pos);
  std::shared_ptr<Representation::HTelePlatform> platformView = std::make_shared<Representation::HTelePlatform>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::VPlatform> ConcreteFactory::createVPlatform(const Vec2D& pos)
{
  std::unique_ptr<Logic::VPlatform> platformModel = std::make_unique<Logic::VPlatform>(pos);
  std::shared_ptr<Representation::VPlatform> platformView = std::make_shared<Representation::VPlatform>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::VTelePlatform> ConcreteFactory::createVTelePlatform(const Vec2D& pos)
{
  std::unique_ptr<Logic::VTelePlatform> platformModel = std::make_unique<Logic::VTelePlatform>(pos);
  std::shared_ptr<Representation::VTelePlatform> platformView = std::make_shared<Representation::VTelePlatform>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  platformModel->registerObserver(platformView);

  return platformModel;
};

std::unique_ptr<Logic::BGTile> ConcreteFactory::createTile(const Vec2D& pos)
{
  std::unique_ptr<Logic::BGTile> tileModel = std::make_unique<Logic::BGTile>(pos);
  //std::shared_ptr<Representation::BGTile> tileView = std::make_shared<Representation::BGTile>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  //tileModel->registerObserver(tileView);

  return tileModel;
};

std::unique_ptr<Logic::Enemy> ConcreteFactory::createEnemy(const Vec2D& pos)
{
  std::unique_ptr<Logic::Enemy> enemyModel = std::make_unique<Logic::Enemy>(pos);
  std::shared_ptr<Representation::Enemy> enemyView = std::make_shared<Representation::Enemy>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  enemyModel->registerObserver(enemyView);

  return enemyModel;
};

std::unique_ptr<Logic::ShootingEnemy> ConcreteFactory::createShootingEnemy(const Vec2D& pos)
{
  std::unique_ptr<Logic::ShootingEnemy> enemyModel = std::make_unique<Logic::ShootingEnemy>(pos);
  std::shared_ptr<Representation::ShootingEnemy> enemyView = std::make_shared<Representation::ShootingEnemy>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  enemyModel->registerObserver(enemyView);

  return enemyModel;
};

std::unique_ptr<Logic::PlayerBullet> ConcreteFactory::createPlayerBullet(const Vec2D& pos)
{
  std::unique_ptr<Logic::PlayerBullet> bulletModel = std::make_unique<Logic::PlayerBullet>(pos);
  std::shared_ptr<Representation::PlayerBullet> bulletView = std::make_shared<Representation::PlayerBullet>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  bulletModel->registerObserver(bulletView);

  return bulletModel;
};

std::unique_ptr<Logic::EnemyBullet> ConcreteFactory::createEnemyBullet(const Vec2D& pos)
{
  std::unique_ptr<Logic::EnemyBullet> bulletModel = std::make_unique<Logic::EnemyBullet>(pos);
  std::shared_ptr<Representation::EnemyBullet> bulletView = std::make_shared<Representation::EnemyBullet>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  bulletModel->registerObserver(bulletView);

  return bulletModel;
};

std::shared_ptr<Logic::Spikes> ConcreteFactory::createSpikes(const Vec2D& pos)
{
  std::shared_ptr<Logic::Spikes> bonusModel = std::make_shared<Logic::Spikes>(pos);
  std::shared_ptr<Representation::Spikes> bonusView = std::make_shared<Representation::Spikes>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};

std::shared_ptr<Logic::Spring> ConcreteFactory::createSpring(const Vec2D& pos)
{
  std::shared_ptr<Logic::Spring> bonusModel = std::make_shared<Logic::Spring>(pos);
  std::shared_ptr<Representation::Spring> bonusView = std::make_shared<Representation::Spring>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};

std::shared_ptr<Logic::Heart> ConcreteFactory::createHeart(const Vec2D& pos)
{
  std::shared_ptr<Logic::Heart> bonusModel = std::make_shared<Logic::Heart>(pos);
  std::shared_ptr<Representation::Heart> bonusView = std::make_shared<Representation::Heart>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};

std::shared_ptr<Logic::Jetpack> ConcreteFactory::createJetpack(const Vec2D& pos)
{
  std::shared_ptr<Logic::Jetpack> bonusModel = std::make_shared<Logic::Jetpack>(pos);
  std::shared_ptr<Representation::Jetpack> bonusView = std::make_shared<Representation::Jetpack>(Logic::Camera::getInstance()->toPixelCoordinates(pos));
  bonusModel->registerObserver(bonusView);

  return bonusModel;
};
