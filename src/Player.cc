#include "Player.h" 

Logic::Player::Player(const Vec2D& pos) : Logic::Model(pos, PLAYER_WIDTH, PLAYER_HEIGHT/4), Logic::Moving(Vec2D(0,0)), HP(PLAYER_HP) { }

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

  move(getVelocity());

  if (pos.x < -PLAYER_WIDTH)
    pos.x = SCREENW;

  if (pos.x > SCREENW+PLAYER_WIDTH)
    pos.x = 0;
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

bool Logic::Player::isShooting() const
{
  return state == Shooting;
}

void Logic::Player::reset()
{
  state = None;
}

