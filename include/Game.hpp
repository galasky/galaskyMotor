#ifndef	__GAME_HPP__
#define	__GAME_HPP__

#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "IEntity.hh"
#include "Screen.hh"

class	Game
{
public:
  static Game &instance();

  void	close();
  void	run();
private:
  Game();
  ~Game();

  void		catch_event();
  Screen	_screen;
  Button<Game>	_button;
};

#endif
