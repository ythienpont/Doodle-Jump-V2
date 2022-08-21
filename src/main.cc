#include "Game.h"
#include <iostream>

Logic::Stopwatch* Logic::Stopwatch::instance = 0;
Logic::Random* Logic::Random::instance = 0;

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
