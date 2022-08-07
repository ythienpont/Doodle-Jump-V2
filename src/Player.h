#ifndef PLAYER_H
#define PLAYER_H

#include "Model.h"

const int PLAYER_HP = 3;
const double JUMP_HEIGHT = 25;
const double GRAVITY = 1;
const double PLAYER_WIDTH = 44;
const double PLAYER_HEIGHT = 71;

enum PlayerState { Shooting, Left, Right, None };

namespace Logic
{
  class Player : public Model, public Moving
  {
    int HP;
    PlayerState state;
  public: 
    Player(const Vec2D& pos);
    void jump();
    void update() override;
    bool goingDown() const;

    int getHP() const;
    void setHP(const int newHP);
    void addHP(const int val);

    void setPlayerState(const PlayerState& ps);

    bool isShooting() const;
    void reset();
  };
}
#endif //PLAYER_H
