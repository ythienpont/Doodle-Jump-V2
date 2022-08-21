#ifndef PLAYER_H
#define PLAYER_H

#include "Model.h"
#include "Bonus.h"
#include "Stopwatch.h"

const int PLAYER_HP = 3;
const double JUMP_HEIGHT = 25;
const double GRAVITY = 1;
const double PLAYER_WIDTH = 44;
const double PLAYER_HEIGHT = 71;

enum PlayerState { Shooting, Left, Right, None };

namespace Logic
{
  class Player : public Model, public Moving, public Living
  {
    PlayerState state;
    std::shared_ptr<Bonus> bonus;
    void parseBonus();
  public:
    explicit Player(const Vec2D& pos);
    void jump();
    void update() override;
    bool goingDown() const;
    bool hasBonus() const;

    void setPlayerState(const PlayerState& ps);

    void addBonus(std::shared_ptr<Bonus> theBonus);
    void removeBonus();

    void hit() override;

    bool isShooting() const;
    void reset();
  };
}
#endif //PLAYER_H
