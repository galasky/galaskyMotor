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

void
SoundManager::load(const std::string &sound)
{
  if (_buffer.find(sound) != _buffer.end())
    return ;

  sf::SoundBuffer buffer;

  buffer.loadFromFile(sound);
  _buffer[sound] = buffer;
}

sf::SoundBuffer &
SoundManager::getBuffer(const std::string &sound)
{
  return _buffer[sound];
}
