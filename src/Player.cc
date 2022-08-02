#include "Player.h" 

Player::Player(const Vec2D& pos) : Entity(pos, PLAYER_WIDTH, PLAYER_HEIGHT), Moving(Vec2D(0,0)), HP(PLAYER_HP) { }

void Player::jump() 
{
  addVelocity(Vec2D(0, JUMP_HEIGHT));
}

void Player::update()
{
  addVelocity(Vec2D(0, -GRAVITY));

  move(getVelocity());
}

bool Player::goingDown() const
{
  return getVelocity().y < 0;
}

int Player::getHP() const
{
  return HP;
}

void Player::setHP(const int newHP)
{
  HP = newHP;
}

void Player::addHP(const int val)
{
  HP += val;
}
