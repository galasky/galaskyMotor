#ifndef	__SPRITEMANAGER_HPP__
#define	__SPRITEMANAGER_HPP__

#include <map>
#include "Sprite.hh"
#include "IEntity.hh"

class	SpriteManager
{
public:
  static SpriteManager &instance();
private:
  SpriteManager();
  ~SpriteManager();

  static SpriteManager	_instance;

  std::map<IEntity *, Sprite>	_sprite;
};

#endif
