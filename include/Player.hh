#ifndef	__PLAYER_HH__
#define	__PLAYER_HH__

#include "APlayer.hh"

class	Player : public APlayer
{
public:
  Player();
  ~Player();

  virtual void	left();
  virtual void	right();
  virtual void	catch_event();
private:
};

#endif
