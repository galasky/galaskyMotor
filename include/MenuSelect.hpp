#ifndef	__MENUSELECT_HPP__
#define	__MENUSELECT_HPP__

#include <SFML/Graphics.hpp>
#include "Window.hpp"

template <typename T>
class	MenuSelect
{
public:
  MenuSelect(T *ptr, void (T::* action)(void), const sf::String &txt, const sf::Vector2f &pos = sf::Vector2f(0, 0), int sizeFont = 5)
  {
    _ptr = ptr;
    _action = action;
    _font.loadFromFile("assets/fonts/BlackKnightFLF.ttf");
    _text.setString(txt);
    _text.setFont(_font);
    _text.setCharacterSize(sizeFont);
    _text.setPosition(pos);
  }
  ~MenuSelect()
  {

  }

  void	draw()
  {
    Window::instance().draw(_text);
  }
private:
  T		*_ptr;
  void (T::* _action)(void);
  sf::Font	_font;
  sf::Text	_text;
};

#endif
