#include "Game.h"
#include <iostream>

Representation::Game::Game() : window(sf::VideoMode(SCREENW,SCREENH), "Doodle Jump")
{
  world = std::make_unique<Logic::World>();
}

void Representation::Game::run()
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

void Representation::Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
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

void Representation::Game::processEvents()
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

void Representation::Game::update(const double& deltaTime)
{

}

void Representation::Game::render()
{
  window.clear();
  drawBackground();
  window.display();
}


void Representation::Game::drawBackground()
{
  sf::Texture bgtexture;
  bgtexture.loadFromFile("images/bg.png");

  sf::Sprite background(bgtexture);
  window.draw(background);

}
