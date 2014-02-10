#ifndef	__MENUSELECT_HPP__
#define	__MENUSELECT_HPP__

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Event.hpp"

template <typename T>
class	MenuSelect
{
public:
  MenuSelect(T *ptr, void (T::* action)(void), const sf::String &txt, const sf::Vector2f &pos = sf::Vector2f(0, 0), int sizeFont = 5)
  {
    _ptr = ptr;
    _action = action;
    _sizeFont = sizeFont;
    _font.loadFromFile("assets/fonts/college.ttf");
    _text.setString(txt);
    _text.setFont(_font);
    _text.setCharacterSize(sizeFont);
    _text.setPosition(pos);
    _unselected = sf::Color(12, 182, 0);
    _selected = sf::Color(202, 202, 0);
    _text.setColor(_unselected);
    _select = false;
  }
  ~MenuSelect()
  {

  }

  void	setSelect(bool set)
  {
    if (set == true)
      _text.setColor(_selected);
    else
      _text.setColor(_unselected);
    _select = set;
  }

  bool	testMouse()
  {
    if (Event::instance().mouseMove.y >= _text.getPosition().y && Event::instance().mouseMove.y <= _text.getPosition().y + _sizeFont
	&& Event::instance().mouseMove.x >= _text.getPosition().x && Event::instance().mouseMove.x <= _text.findCharacterPos(_text.getString().getSize()).x)
      return true;
    return false;
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
  sf::Color	_unselected;
  sf::Color	_selected;
  bool		_select;
  int		_sizeFont;
};

#endif
