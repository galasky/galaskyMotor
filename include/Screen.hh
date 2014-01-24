#ifndef	__SCREEN_HH__
#define	__SCREEN_HH__

#include "ILayout.hh"
#include "Sprite.hh"

class	Screen
{
public:
  Screen();
  ~Screen();

  void		draw();
private:
  ILayout	*_layout;
  Sprite	_background;
};

#endif
