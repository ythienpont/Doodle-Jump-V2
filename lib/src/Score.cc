#include "../include/Score.h"

Logic::Score::Score() : amount(0) { }

void Logic::Score::addDelta(const int delta)
{
  amount += delta;

  if (amount < 0)
    amount = 0;
}

void Logic::Score::addDelta(const std::vector<int> deltas)
{
  for (const auto delta : deltas)
  {
    addDelta(delta);
  }
}

int Logic::Score::getAmount() const
{
  return amount;
}
