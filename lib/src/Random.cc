#include "Random.h"

Logic::Random::Random() { }

Logic::Random* Logic::Random::getInstance()
{
  if (!instance) instance = new Random;

  return instance;
}

int Logic::Random::getValue()
{
  unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
  rng.seed(seed);
  return rng();
}
