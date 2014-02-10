#include "Game.hpp"
#include "Window.hpp"
#include "Player.hh"

Game::Game()
  : _buttonGame(this),
    _buttonScreen(&_screen)
{
  _buttonGame.addPressed(sf::Keyboard::Escape, &Game::close);

  _buttonScreen.addReleased(sf::Keyboard::Down, &Screen::down);
  _buttonScreen.addReleased(sf::Keyboard::Up, &Screen::up);
  _buttonScreen.addReleased(sf::Keyboard::Return, &Screen::enter);
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
      _buttonGame.catch_event();
      _buttonScreen.catch_event();
      if (Event::instance().type == sf::Event::MouseMoved)
	{
	  _screen.mouseMoved();
	}
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
