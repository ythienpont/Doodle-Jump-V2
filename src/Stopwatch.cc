#include "Stopwatch.h"


Logic::Stopwatch::Stopwatch()
{
  time = std::chrono::steady_clock::now();
}

Logic::Stopwatch* Logic::Stopwatch::getInstance()
{
  if (!instance) instance = new Stopwatch;

  return instance;
}

void Logic::Stopwatch::restart()
{
  time = std::chrono::steady_clock::now();
}

double Logic::Stopwatch::getElapsedTime() const
{
  std::chrono::duration<double> duration = std::chrono::steady_clock::now() - time;

  return duration.count();
}
