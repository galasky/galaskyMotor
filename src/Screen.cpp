#include <boost/foreach.hpp>
#include <iostream>
#include <fstream>
#include "Screen.hh"
#include "MenuLayout.hh"

Screen::Screen()
{
}

Screen::~Screen()
{
}

void
Screen::loadXmlFile(const std::string &xmlFile)
{
  std::ifstream myfile(xmlFile.c_str());

  if (myfile.is_open())
    {
      boost::property_tree::ptree pt;
      boost::property_tree::read_xml(myfile, pt);

      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v, pt.get_child("Menu") )
	{
	  Layout l;

	  if (v.first == "<xmlattr>")
	    {
	      _music.openFromFile(v.second.get<std::string>("music"));
	    }
	  else if (v.first == "Layout")
	    {
	      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v2, v.second )
		{
		  if (v2.first == "<xmlattr>")
		    {
		      l.name = v2.second.get<std::string>("name");
		      l.soundButton = v2.second.get<std::string>("soundButton");
		      l.background = v2.second.get<std::string>("background");
		    }		  
		  else if (v2.first == "Button")
		    {
		      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v3, v2.second )
			{
			  sButton b;
			  
			  if (v3.first == "<xmlattr>")
			    {
			      b.inFile = "";
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
		  else if (v2.first == "EditText")
		    {
		      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v3, v2.second )
			{
			  EditText *e = new EditText;
			  
			  if (v3.first == "<xmlattr>")
			    {
			      e->font = v3.second.get<std::string>("font");
			      e->text = v3.second.get<std::string>("text");
			      e->x = v3.second.get<int>("x");
			      e->y = v3.second.get<int>("y");
			      e->fontSize = v3.second.get<int>("fontSize");
			      l.edit_text.push_back(e);
			    }
			}
		    }
		  else if (v2.first == "Save")
		    {
		      BOOST_FOREACH(boost::property_tree::ptree::value_type const& v3, v2.second )
			{
			  sButton b;
			  
			  if (v3.first == "<xmlattr>")
			    {
			      b.onClick = v3.second.get<std::string>("onClick");
			      b.font = v3.second.get<std::string>("font");
			      b.inFile = v3.second.get<std::string>("inFile");
			      b.text = v3.second.get<std::string>("text");
			      b.x = v3.second.get<int>("x");
			      b.y = v3.second.get<int>("y");
			      b.fontSize = v3.second.get<int>("fontSize");
			      l.save.push_back(b);
			    }
			}
		    }

		}
	      _layout[l.name] = new MenuLayout(this, l);
	    }
	}

      _itLayout = _layout.begin();
      myfile.close();
      _music.play();
    }
  else
    std::cout << "error loadXmlFile" << std::endl;
}

void
Screen::down()
{
  if (_layout.size() > 0)
  _itLayout->second->down();
}

void
Screen::up()
{
  if (_layout.size() > 0)
  _itLayout->second->up();
}

void
Screen::enter()
{
  if (_layout.size() > 0)
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
  if (_layout.size() > 0)
  _itLayout->second->mouseMoved();
}

void
Screen::click()
{
  if (_layout.size() > 0)
  _itLayout->second->click();
}

void
Screen::text()
{
  _itLayout->second->text();
}

void
Screen::draw()
{
  if (_layout.size() > 0)
    _itLayout->second->draw();
}

EditText::EditText()
{

}

EditText::EditText(EditText *other)
{
  if (this != other)
    {
      text = other->text;
      _font.loadFromFile(other->font);
      _text.setString(other->text);
      _text.setFont(_font);
      fontSize = other->fontSize;
      _text.setCharacterSize(other->fontSize);
      _text.setPosition(other->x, other->y);
      _unselected = sf::Color(12, 182, 0);
      _selected = sf::Color(202, 202, 0);
      _text.setColor(_unselected);
      _select = false;
    }
}

EditText::~EditText()
{

}

void
EditText::draw()
{
  Window::instance().draw(_text);
}

bool
EditText::testClick()
{
  if (_select == true)
    return false;
  if (Event::instance().mouseButton.y >= _text.getPosition().y && Event::instance().mouseButton.y <= _text.getPosition().y + fontSize
      && Event::instance().mouseButton.x >= _text.getPosition().x && Event::instance().mouseButton.x <= _text.findCharacterPos(_text.getString().getSize()).x)
    return true;
  return false;
}

void
EditText::setSelect(bool set)
{
  if (set == true)
    _text.setColor(_selected);
  else
    _text.setColor(_unselected);
  _select = set;
}

void
EditText::texte()
{
  if (static_cast<int>(Event::instance().text.unicode) == 8)
    {
      _value = _value.substr(0, _value.length() - 1);
    }
  else
    {
      _value += static_cast<char>(Event::instance().text.unicode);
    }
  _text.setString(text + " " + _value);
}
