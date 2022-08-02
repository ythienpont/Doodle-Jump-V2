#include "Stopwatch.h"


Stopwatch::Stopwatch()
{
  time = std::chrono::steady_clock::now();
}

Stopwatch* Stopwatch::getInstance()
{
  if (!instance) instance = new Stopwatch;

  return instance;
}

void Stopwatch::restart()
{
  time = std::chrono::steady_clock::now();
}

double Stopwatch::getElapsedTime() const
{
  std::chrono::duration<double> duration = std::chrono::steady_clock::now() - time;

  return duration.count();
}
