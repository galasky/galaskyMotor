#include "SpriteManager.hpp"

SpriteManager SpriteManager::_instance=SpriteManager();

SpriteManager::SpriteManager()
{
  
}

SpriteManager::~SpriteManager()
{
  
}

SpriteManager &
SpriteManager::instance()
{
  return _instance;
}
