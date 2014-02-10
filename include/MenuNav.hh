#ifndef	__MENUNAV_HH__
#define	__MENUNAV_HH__

#include <list>
//#include <SFML/Audio.hpp>
#include "MenuSelect.hpp"
//#include "SoundManager.hpp"

template <typename T>
class	MenuNav
{
public:
  MenuNav()
  {
  }
  ~MenuNav()
  {

  }

  void	draw()
  {
    for (typename std::list<MenuSelect<T> *>::iterator it = _nav.begin(); it != _nav.end(); it++)
      (*it)->draw();
  }

  void	up()
  {
    (*_selected)->setSelect(false);
    if (_selected == _nav.begin())
      _selected = _nav.end();
    _selected--;
    (*_selected)->setSelect(true);    
  }

  void	down()
  {
    (*_selected)->setSelect(false);
    _selected++;
    if (_selected == _nav.end())
      _selected = _nav.begin();
    (*_selected)->setSelect(true);
  }

  void	enter()
  {

  }

  void	mouseMoved()
  {
    for (typename std::list<MenuSelect<T> *>::iterator it = _nav.begin(); it != _nav.end(); it++)
      if ((*it)->testMouse() == true)
	{
	  (*_selected)->setSelect(false);
	  _selected = it;
	  (*_selected)->setSelect(true);
	}
  }

  void	push_back(MenuSelect<T> *add)
  {
    _nav.push_back(add);
    if (_nav.size() == 1)
      {
	(*_nav.begin())->setSelect(true);
	_selected = _nav.begin();
      }
  }
private:
  std::list<MenuSelect<T> *>			_nav;
  typename std::list<MenuSelect<T> *>::iterator _selected;
};

#endif
