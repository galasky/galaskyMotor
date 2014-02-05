#ifndef	__MENUNAV_HH__
#define	__MENUNAV_HH__

#include <list>
#include "MenuSelect.hpp"

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
    (*_nav.begin())->draw();
  }
  void	push_back(MenuSelect<T> *add)
  {
    _nav.push_back(add);
  }
private:
  std::list<MenuSelect<T> *>	_nav;
};

#endif
