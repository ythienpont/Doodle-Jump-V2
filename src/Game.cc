#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(SCREENW,SCREENH), "Doodle Jump")
{
  world = std::make_unique<World>();
}

void Game::run()
{
  double timeSinceLastUpdate = 0;
  Stopwatch* clock = Stopwatch::getInstance();

  while (window.isOpen())
  {
    processEvents();
    timeSinceLastUpdate += clock->getElapsedTime();
    clock->restart();
    while (timeSinceLastUpdate > timePerFrame)
    {
      timeSinceLastUpdate -= timePerFrame;
      processEvents();
      update(timePerFrame);
    }
    render();
  }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
  switch (key)
  {
    case sf::Keyboard::X:
      window.close();
      break;
    case sf::Keyboard::A:
      // Move Left
      break;
    case sf::Keyboard::D:
      //Move Right
      break;
  }
}

void Game::processEvents()
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    switch (event.type)
    {
      case sf::Event::KeyPressed:
        handlePlayerInput(event.key.code, true);
        break;
      case sf::Event::KeyReleased:
        handlePlayerInput(event.key.code, false);
        break;
      case sf::Event::Closed:
        window.close();
        break;
    }
  }
}

void Game::update(const double& deltaTime)
{

}

void Game::render()
{
  window.clear();
  drawBackground();
  window.display();
}


void Game::drawBackground()
{
  sf::Texture bgtexture;
  bgtexture.loadFromFile("images/bg.png");

  sf::Sprite background(bgtexture);
  window.draw(background);

}
