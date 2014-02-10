#ifndef	__SOUNDMANAGER_HPP__
#define	__SOUNDMANAGER_HPP__

#include <SFML/Audio.hpp>

class	SoundManager
{
public:
  static SoundManager &instance();
private:
  SoundManager();
  ~SoundManager();
};

#endif
