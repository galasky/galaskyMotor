#include "SoundManager.hpp"

SoundManager::SoundManager()
{
  
}

SoundManager::~SoundManager()
{
  
}

SoundManager &
SoundManager::instance()
{
  static SoundManager _instance;

  return _instance;
}
