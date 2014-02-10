#ifndef	__SOUNDMANAGER_HPP__
#define	__SOUNDMANAGER_HPP__

#include <SFML/Audio.hpp>
#include <map>

class	SoundManager
{
public:
  static SoundManager	&instance();
  void			load(const std::string &);
  sf::SoundBuffer	&getBuffer(const std::string &);
private:
  SoundManager();
  ~SoundManager();

  std::map<std::string, sf::SoundBuffer>	_buffer;
};

#endif
