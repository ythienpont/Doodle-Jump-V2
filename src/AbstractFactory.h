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

class AbstractFactory 
{
  virtual std::shared_ptr<Entity> createPlayer(const Vec2D& pos)=0;
  virtual std::shared_ptr<Entity> createPlatform(const Vec2D& pos)=0;
  virtual std::shared_ptr<Entity> createTile(const Vec2D& pos)=0;
  virtual std::shared_ptr<Entity> createEnemy(const Vec2D& pos)=0;
};

class ModelFactory : public AbstractFactory
{
  std::shared_ptr<Entity> createPlayer(const Vec2D& pos) override;
  std::shared_ptr<Entity> createPlatform(const Vec2D& pos) override;
  std::shared_ptr<Entity> createTile(const Vec2D& pos) override;
  std::shared_ptr<Entity> createEnemy(const Vec2D& pos) override;
};

class ViewFactory : public AbstractFactory
{
  std::shared_ptr<Entity> createPlayer(const Vec2D& pos) override;
  std::shared_ptr<Entity> createPlatform(const Vec2D& pos) override;
  std::shared_ptr<Entity> createTile(const Vec2D& pos) override;
  std::shared_ptr<Entity> createEnemy(const Vec2D& pos) override;
};

#endif //ABSTRACTFACTORY_H
