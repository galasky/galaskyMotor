#ifndef	__SPRITE_HH__
#define	__SPRITE_HH__

#include <SFML/Graphics.hpp>

class	Sprite
{
public:
  Sprite(const std::string &);
  ~Sprite();

  void	animate();
  void	draw();
private:
  sf::Texture	_texture;
  sf::Sprite	_sprite;
};

#endif
