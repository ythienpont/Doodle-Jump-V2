#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Stopwatch.h"
#include "Random.h"
#include "World.h"


namespace Representation
{
  class Game
  {
  public:
    Game();
    ~Game();
    void run();
  private:
    void processEvents();
    void update(const double& deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void drawBackground();
    void drawScore();
    void drawPlayerHP();
    void drawGameOver();

    sf::RenderWindow window;

    std::unique_ptr<Logic::World> world;
    std::shared_ptr<AbstractFactory> factory;
  };
}

#endif //GAME_H
