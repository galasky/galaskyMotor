#ifndef	__SCREEN_HH__
#define	__SCREEN_HH__

#include <map>
#include <list>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "ILayout.hh"
#include "Sprite.hh"

typedef boost::gregorian::date Date;

class sButton
{
public:
  std::string	onClick;
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
  std::list<sButton>	buttons;
};

class	Screen
{
public:
  Screen();
  ~Screen();

  void						loadXmlFile();
  void						draw();
  void						down();
  void						up();
  void						enter();
  void						toLayout(const std::string &);
  void						mouseMoved();
  void						click();

private:
  std::map<std::string, ILayout *>		_layout;
  std::map<std::string, ILayout *>::iterator	_itLayout;
};

#endif
