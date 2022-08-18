#include "Player.h"
#include <iostream>

Logic::Player::Player(const Vec2D& pos) : Logic::Model(pos, PLAYER_WIDTH, PLAYER_HEIGHT/4, 0), Logic::Moving(Vec2D(0,0)), Living(PLAYER_HP), bonus(nullptr), state(None) { }

void Logic::Player::jump()
{
    setVelocity(Vec2D(0, JUMP_HEIGHT));
}

void Logic::Player::update()
{
  addVelocity(Vec2D(0, -GRAVITY));
  switch (state)
  {
    case Left:
      setVelocity(Vec2D(-8, getVelocity().y));
      break;
    case Right:
      setVelocity(Vec2D(8, getVelocity().y));
      break;
    case Shooting:
      break;
    default:
      setVelocity(Vec2D(0, getVelocity().y));
      break;
  }

  if (hasBonus() and bonus->getVelocity() > 0)
  {
    setVelocity(Vec2D(getVelocity().x, bonus->getVelocity()));
    bonus->decreaseDistance(getVelocity().y);
  }

  if (hasBonus() and bonus->isDone())
    removeBonus();

  move(getVelocity());

  if (pos.x < -PLAYER_WIDTH)
    pos.x = SCREENW;

  if (pos.x > SCREENW+PLAYER_WIDTH)
    pos.x = 0;

  if (Camera::getInstance()->isOutOfLowerBounds(getPosition()))
    kill();
  notifyObservers();
}

void Logic::Player::setPlayerState(const PlayerState& ps)
{
  state = ps;
}

bool Logic::Player::goingDown() const
{
  return getVelocity().y < -2; // Yes, under 0 is also 'going down' but this gives a more natural jump effect
}

bool Logic::Player::isShooting() const
{
  return (state == Shooting and bonus == nullptr);
}

void Logic::Player::reset()
{
  state = None;
}


bool Logic::Player::hasBonus() const
{
  return bonus != nullptr;
}

void Logic::Player::addBonus(std::shared_ptr<Bonus> theBonus)
{
  bonus = theBonus;
  parseBonus();
}

void Logic::Player::removeBonus()
{
  bonus = nullptr;
}

void Logic::Player::parseBonus()
{
  if (bonus->getDistance() == 0)
  {
    addHP(bonus->getHealth());
    if (bonus->getJumpMultiplier() > 0)
      setVelocity(Vec2D(0, bonus->getJumpMultiplier()*JUMP_HEIGHT));
  }

  if (bonus->getVelocity() > 0)
    setVelocity(Vec2D(0, bonus->getVelocity()));
}

void Logic::Player::hit()
{
  if (!hasBonus() and getVelocity().y <= JUMP_HEIGHT)
    addHP(-1);
}
