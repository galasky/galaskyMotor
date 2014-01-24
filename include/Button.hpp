#ifndef	__BUTTON_HPP__
#define	__BUTTON_HPP__

#include <map>
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Event.hpp"
#include <iostream>

template <typename T>
class	Button
{
public:

  Button(T *ptr)
  {
    _ptr = ptr;
  }
  ~Button() {}

  void	addPressed(sf::Keyboard::Key key,  void (T::* action)(void))
  {
    std::cout << key << std::endl;
    _actionPressed[key] = action;
  }
  void	addReleased(sf::Keyboard::Key key,  void (T::* action)(void))
  {
    _actionReleased[key] = action;
  }

  void	catch_event()
  {
    sf::Event event = Event::instance();

    if (event.type == sf::Event::KeyPressed && _actionPressed[event.key.code] != NULL)
      {
	(_ptr->*_actionPressed[event.key.code])();
      }
    else if (event.type == sf::Event::KeyReleased && _actionReleased[event.key.code] != NULL)
      {
	(_ptr->*_actionReleased[event.key.code])();
      }
  }
private:
  std::map<sf::Keyboard::Key, void (T::*)(void)>	_actionPressed;
  std::map<sf::Keyboard::Key, void (T::*)(void)>	_actionReleased;
  T							*_ptr;
};

#endif
