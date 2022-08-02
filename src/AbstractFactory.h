#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "Vec2D.h"
#include <SFML/Graphics.hpp>

class AbstractFactory 
{
  virtual void createPlayer(const Vec2D& pos)=0;
  virtual void createPlatform(const Vec2D& pos)=0;
  virtual void createTile(const Vec2D& pos)=0;
  virtual void createEnemy(const Vec2D& pos)=0;
};

class GameFactory : public AbstractFactory
{

};

class SfFactory : public AbstractFactory
{

};

#endif //ABSTRACTFACTORY_H
