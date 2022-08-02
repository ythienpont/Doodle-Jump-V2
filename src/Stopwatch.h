#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

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

#endif //STOPWATCH_H
