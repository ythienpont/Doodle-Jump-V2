#include "AbstractFactory.h"

std::shared_ptr<Entity> ModelFactory::createPlayer(const Vec2D& pos)
{
  return std::make_shared<Logic::Player>(pos);
};

std::shared_ptr<Entity> ModelFactory::createPlatform(const Vec2D& pos)
{
  return std::make_shared<Logic::Platform>(pos);
};

std::shared_ptr<Entity> ViewFactory::createPlayer(const Vec2D& pos)
{
  return std::make_shared<Representation::Player>(pos);
};

std::shared_ptr<Entity> ViewFactory::createPlatform(const Vec2D& pos)
{
  return std::make_shared<Representation::Platform>(pos);
};
