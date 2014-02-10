#ifndef	__MENULAYOUT_HH__
#define	__MENULAYOUT_HH__

#include <list>
#include "ILayout.hh"
#include "MenuSelect.hpp"
#include "MenuNav.hh"

class	MenuLayout : public ILayout
{
public:
  MenuLayout();
  ~MenuLayout();

  void		nothing();
  virtual void	draw();
  virtual void	down();
  virtual void	up();
  virtual void	enter();
  virtual void	mouseMoved();
  void		createGame();

private:
  MenuNav<MenuLayout>	_menu;
};

#endif
