#include "Game.h"
#include <iostream>

Representation::Game::Game() : window(sf::VideoMode(SCREENW,SCREENH), "Doodle Jump")
{
  factory = std::make_shared<ConcreteFactory>();
  world = std::make_unique<Logic::World>(factory);
}

void Representation::Game::run()
{
  double timeSinceLastUpdate = 0;
  Logic::Stopwatch* clock = Logic::Stopwatch::getInstance();
  int i = 0;

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
  if (!isPressed)
  {
    world->setPlayerState(None);
    return;
  }

  switch (key)
  {
    case sf::Keyboard::X:
      window.close();
      break;
    case sf::Keyboard::A:
      world->setPlayerState(Left);
      break;
    case sf::Keyboard::D:
      world->setPlayerState(Right);
      break;
    case sf::Keyboard::W:
      world->setPlayerState(Shooting);
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
  world->spawnEntities(factory);
  world->update();
}

void Representation::Game::render()
{
  window.clear(sf::Color::Black);
  //drawBackground();

  std::vector<std::shared_ptr<Representation::View> > sprites = world->getSprites();

  for (auto& sprite : sprites)
  {
    window.draw(*sprite);
  }
  window.display();
}


void Representation::Game::drawBackground()
{
  sf::Texture bgtexture;
  bgtexture.loadFromFile("images/bg.png");

  sf::Sprite background(bgtexture);
  window.draw(background);

}
