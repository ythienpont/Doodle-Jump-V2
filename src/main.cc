#include "Game.h"
#include <iostream>

Stopwatch* Stopwatch::instance = 0;
Random* Random::instance = 0;

int main( int argc, char* argv[])
{
  try
  {
    Representation::Game game;
    game.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "\n" << e.what() << std::endl;
  }
}
