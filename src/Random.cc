#include "Random.h"

Random::Random() { }

Random* Random::getInstance()
{
  if (!instance) instance = new Random;

  return instance;
}

int Random::getValue()
{
  unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count(); 
  rng.seed(seed);
  return rng();
}
