#include <boost/foreach.hpp>
#include <iostream>
#include <fstream>
#include "Screen.hh"
#include "MenuLayout.hh"

Screen::Screen()
{
  this->loadXmlFile();
}

Screen::~Screen()
{
}

void
Screen::loadXmlFile()
{
  std::ifstream myfile ("assets/menu/menu.xml");

  if (myfile.is_open())
    {
      boost::property_tree::ptree pt;
      boost::property_tree::read_xml(myfile, pt);

      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v, pt.get_child("Menu") )
	{
	  Layout l;

	  if (v.first == "Layout")
	    {
	      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v2, v.second )
		{
		  if (v2.first == "<xmlattr>")
		    {
		      l.name = v2.second.get<std::string>("name");
		      l.background = v2.second.get<std::string>("background");	
		    }		  
		  if (v2.first == "Button")
		    {
		      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v3, v2.second )
			{
			  sButton b;
			  
			  if (v3.first == "<xmlattr>")
			    {
			      b.onClick = v3.second.get<std::string>("onClick");
			      b.font = v3.second.get<std::string>("font");
			      b.text = v3.second.get<std::string>("text");
			      b.x = v3.second.get<int>("x");
			      b.y = v3.second.get<int>("y");
			      b.fontSize = v3.second.get<int>("fontSize");
			      l.buttons.push_back(b);
			    }
			}
		    }
		}
	      _layout[l.name] = new MenuLayout(this, l);
	    }
	}

      _itLayout = _layout.begin();
      myfile.close();
    }
  else
    std::cout << "error loadXmlFile" << std::endl;
}

void
Screen::down()
{
  _itLayout->second->down();
}

void
Screen::up()
{
  _itLayout->second->up();
}

void
Screen::enter()
{
  _itLayout->second->enter();
}

void
Screen::toLayout(const std::string &layout)
{
  if (layout == "finish")
    Window::instance().close();
  if (_layout.find(layout) != _layout.end())
    {
      _itLayout = _layout.find(layout);
    }
  else
    std::cout << "Layout " << layout << " doesn't exist" << std::endl;
}

void
Screen::mouseMoved()
{
  _itLayout->second->mouseMoved();
}

void
Screen::click()
{
  _itLayout->second->click();
}

void
Screen::draw()
{
  _itLayout->second->draw();
}
