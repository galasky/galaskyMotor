#ifndef	__APLAYER_HH__
#define	__APLAYER_HH__

#include "IEntity.hh"
#include "Button.hpp"

class	APlayer : public IEntity
{
public:
  APlayer();
  ~APlayer();

  virtual void		draw();
  virtual void		left() = 0;
  virtual void		right() = 0;
  virtual void		catch_event() = 0;
protected:
  Button<APlayer>	_button;
};

#endif
