#ifndef	__MENULAYOUT_HH__
#define	__MENULAYOUT_HH__

#include "ILayout.hh"
#include "MenuSelect.hpp"

class	MenuLayout : public ILayout
{
public:
  MenuLayout();
  ~MenuLayout();

  void		nothing();
  virtual void	draw();
private:
  MenuSelect<MenuLayout>	_start;
};

#endif
