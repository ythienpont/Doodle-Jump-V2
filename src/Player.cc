#include "Player.h" 

Logic::Player::Player(const Vec2D& pos) : Logic::Entity::Model(pos, PLAYER_WIDTH, PLAYER_HEIGHT), Logic::Moving(Vec2D(0,0)), HP(PLAYER_HP) { }

void Logic::Player::jump() 
{
  addVelocity(Vec2D(0, JUMP_HEIGHT));
}

void Logic::Player::update()
{
  addVelocity(Vec2D(0, -GRAVITY));

  move(getVelocity());
}

bool Logic::Player::goingDown() const
{
  return getVelocity().y < 0;
}

int Logic::Player::getHP() const
{
  return HP;
}

void Logic::Player::setHP(const int newHP)
{
  HP = newHP;
}

void Logic::Player::addHP(const int val)
{
  HP += val;
}
