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

class sButton : public Widget
{
public:
  std::string	onClick;
  std::string	text;
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

private:
  std::map<std::string, ILayout *>		_layout;
  std::map<std::string, ILayout *>::iterator	_itLayout;
  Sprite					_background;
};

#endif
