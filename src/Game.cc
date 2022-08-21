#include "Game.h"
#include <iostream>

Representation::Game::Game() : window(sf::VideoMode(SCREENW,SCREENH), "Doodle Jump")
{
  factory = std::make_shared<ConcreteFactory>();
  world = std::make_unique<Logic::World>(factory);
}

Representation::Game::~Game()
{
  world = nullptr;
  factory = nullptr;
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
      break;
    case sf::Keyboard::Enter:
      world = std::make_unique<Logic::World>(factory);
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
  world->update(factory);
}

void Representation::Game::render()
{
  window.clear(sf::Color::Black);

  std::vector<std::shared_ptr<Logic::Observer> > sprites = world->getView();

  for (auto& sprite : sprites)
  {
    window.draw(*std::static_pointer_cast<Representation::View>(sprite));
  }

  if (world->isGameOver())
    drawGameOver();

  drawScore();
  drawPlayerHP();
  window.display();
}

void Representation::Game::drawScore()
{
  sf::Font font;

  // Load it from a file
  if (!font.loadFromFile("upheavtt.ttf"))
  {
    std::cerr << "Couldn't load upheavtt.ttf\n";
  }

  // Create a text which uses our font
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(30);
  text.setString(std::to_string(world->getScore()));
  text.setFillColor(sf::Color::White);
  text.setPosition(sf::Vector2f(10,2));
  window.draw(text);
}

void Representation::Game::drawPlayerHP()
{
  sf::RectangleShape hp;
  hp.setFillColor(sf::Color::Green);
  hp.setSize(sf::Vector2f(20,20));
  hp.setPosition(sf::Vector2f(SCREENW-10,30));

  for (int i = 0; i < world->getPlayerHP(); ++i)
  {
    hp.setPosition(sf::Vector2f(SCREENW-(50*(1+i)),15));
    window.draw(hp);
  }
}

void Representation::Game::drawGameOver()
{
  sf::Font font;

  // Load it from a file
  if (!font.loadFromFile("upheavtt.ttf"))
  {
    std::cerr << "Couldn't load upheavtt.ttf\n";
  }

  // Create a text which uses our font
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(80);
  text.setString("Game Over!");
  text.setFillColor(sf::Color::White);
  text.setPosition(sf::Vector2f(17, (double)SCREENH/2-100));
  window.draw(text);
  text.setCharacterSize(30);
  text.setString("Press <Enter> to play again");
  text.setPosition(sf::Vector2f(5, (double)SCREENH/2));
  window.draw(text);
}

void Representation::Game::drawBackground()
{
  sf::Texture bgtexture;
  bgtexture.loadFromFile("images/bg.png");

  sf::Sprite background(bgtexture);
  window.draw(background);

}
