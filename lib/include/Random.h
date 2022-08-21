#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

namespace Logic
{
  class Random 
  {
  private:
    static Random* instance;
    Random();
    std::default_random_engine rng = std::default_random_engine();
  public:
    static Random* getInstance();
    int getValue();
  };
}
#endif //RANDOM_H
