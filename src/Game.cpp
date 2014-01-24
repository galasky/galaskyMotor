#include "Game.hpp"
#include "Window.hpp"
#include "Player.hh"

Game::Game()
  : _button(this)
{
  _button.addPressed(sf::Keyboard::Escape, &Game::close);
}

Game::~Game()
{
  
}

Game &
Game::instance()
{
  static Game _instance;

  return _instance;
}

void
Game::close()
{
  Window::instance().close();
}

void
Game::catch_event()
{
  while (Window::instance().pollEvent(Event::instance()))
    {
      _button.catch_event();
    }  
}

void
Game::run()
{
  while (Window::instance().isOpen())
    {
      this->catch_event();
      Window::instance().clear();
      _screen.draw();
      Window::instance().display();
    }
}
