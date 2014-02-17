#ifndef	__MENULAYOUT_HH__
#define	__MENULAYOUT_HH__

#include <list>
#include "ILayout.hh"
#include "MenuSelect.hpp"
#include "MenuNav.hh"
#include "Screen.hh"

class	Screen;

class	MenuLayout : public ILayout
{
public:
  MenuLayout(Screen *, Layout &);
  ~MenuLayout();

  void		nothing();
  virtual void	draw();
  virtual void	down();
  virtual void	up();
  virtual void	enter();
  virtual void	mouseMoved();
  virtual void	click();
  virtual void	text();

private:
  MenuNav<Screen>	_menu;
  Screen		*_screen;
  Sprite		_background;
};

#endif
