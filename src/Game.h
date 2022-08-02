#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Stopwatch.h"
#include "Random.h"
#include "World.h"

const int SCREENW = 480;
const int SCREENH = 700;
const double timePerFrame = (double) 1/60;

class Game 
{
public: 
  Game();
  void run();
private:
  void processEvents();
  void update(const double& deltaTime);
  void render();
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
  void drawBackground();

  sf::RenderWindow window;

  std::unique_ptr<World> world;
};

#endif //GAME_H
