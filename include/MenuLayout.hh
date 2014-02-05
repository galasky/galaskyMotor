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
private:
  MenuNav<MenuLayout>	_menu;
};

#endif
