#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

const double timePerFrame = (double) 1/60;

namespace Logic
{
  class Stopwatch
  {
  private:
    static Stopwatch* instance;
    Stopwatch();
    std::chrono::time_point<std::chrono::steady_clock> time;

  public:
    static Stopwatch* getInstance();

    void restart();

    double getElapsedTime() const;

  };
}
#endif //STOPWATCH_H
