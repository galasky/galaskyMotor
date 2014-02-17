#ifndef	__SCREEN_HH__
#define	__SCREEN_HH__

#include <map>
#include <list>
#include <SFML/Audio.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "ILayout.hh"
#include "Sprite.hh"
#include "Window.hpp"

typedef boost::gregorian::date Date;

class sButton
{
public:
  std::string	onClick;
  std::string	inFile;
  std::string	text;
  std::string	font;
  int		x;
  int		y;
  int		fontSize;
};

class EditText
{
public:
  EditText();
  EditText(EditText *);
  ~EditText();

  bool	testClick();
  void	setSelect(bool);
  void	texte();
  void	draw();
  
  sf::Text	_text;
  sf::Font	_font;
  sf::Color	_selected;
  sf::Color	_unselected;
  std::string	_value;
  bool		_select;
  
  std::string	text;
  std::string	font;
  int		x;
  int		y;
  int		fontSize;
};

struct Layout
{
  std::string		background;
  std::string		name;
  std::string		soundButton;
  std::list<sButton>	buttons;
  std::list<EditText *>	edit_text;
  std::list<sButton>	save;
};

class	Screen
{
public:
  Screen();
  ~Screen();

  void						loadXmlFile(const std::string &);
  void						draw();
  void						down();
  void						up();
  void						enter();
  void						toLayout(const std::string &);
  void						mouseMoved();
  void						click();
  void						text();

private:
  std::map<std::string, ILayout *>		_layout;
  std::map<std::string, ILayout *>::iterator	_itLayout;
  sf::Music					_music;
};

#endif
