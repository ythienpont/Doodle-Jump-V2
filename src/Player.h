#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

const int PLAYER_HP = 3;
const double JUMP_HEIGHT = 10;
const double GRAVITY = 2;
const double PLAYER_WIDTH = 44;
const double PLAYER_HEIGHT = 71;

class Player : public Entity, Moving
{
  int HP;
public: 
  Player(const Vec2D& pos);
  void jump();
  void update() override;
  bool goingDown() const;

  int getHP() const;
  void setHP(const int newHP);
  void addHP(const int val);
};

#endif //PLAYER_H
