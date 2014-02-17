#ifndef	__MENUSELECT_HPP__
#define	__MENUSELECT_HPP__

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Event.hpp"
#include "Screen.hh"

template <typename T>
class	MenuSelect
{
public:
  MenuSelect(T *ptr, void (T::* action)(const std::string &), const sButton &widget)
  {
    _inFile = widget.inFile;
    _ptr = ptr;
    _link = widget.onClick;
    _action = action;
    _sizeFont = widget.fontSize;
    _font.loadFromFile(widget.font);
    _text.setString(widget.text);
    _text.setFont(_font);
    _text.setCharacterSize(_sizeFont);
    _text.setPosition(widget.x, widget.y);
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

  bool	isSave()
  {
    if (_inFile == "")
      return false;
    return true;
  }

  std::string	getInFile()
  {
    return (_inFile);
  }

  void	enter()
  {
    (_ptr->*_action)(_link);
  }

  bool	testMouse()
  {
    if (_select == true)
      return false;
    if (Event::instance().mouseMove.y >= _text.getPosition().y && Event::instance().mouseMove.y <= _text.getPosition().y + _sizeFont
	&& Event::instance().mouseMove.x >= _text.getPosition().x && Event::instance().mouseMove.x <= _text.findCharacterPos(_text.getString().getSize()).x)
      return true;
    return false;
  }

  bool	testClick()
  {
    if (Event::instance().mouseButton.y >= _text.getPosition().y && Event::instance().mouseButton.y <= _text.getPosition().y + _sizeFont
	&& Event::instance().mouseButton.x >= _text.getPosition().x && Event::instance().mouseButton.x <= _text.findCharacterPos(_text.getString().getSize()).x)
      return true;
    return false;
  }

  void	draw()
  {
    Window::instance().draw(_text);
  }
private:
  T		*_ptr;
  void (T::* _action)(const std::string &);
  sf::Font	_font;
  sf::Text	_text;
  sf::Color	_unselected;
  sf::Color	_selected;
  std::string	_link;
  std::string	_inFile;
  bool		_select;
  int		_sizeFont;
};

#endif
