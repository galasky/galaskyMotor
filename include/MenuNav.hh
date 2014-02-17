#ifndef	__MENUNAV_HH__
#define	__MENUNAV_HH__

#include <list>
#include <SFML/Audio.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "MenuSelect.hpp"
#include "SoundManager.hpp"

template <typename T>
class	MenuNav
{
public:
  MenuNav(const std::string &soundButton)
  {
    SoundManager::instance().load(soundButton);
    _sound.setBuffer(SoundManager::instance().getBuffer(soundButton));
    _eselected = _editText.end();
  }
  ~MenuNav()
  {

  }

  void	draw()
  {
    for (typename std::list<MenuSelect<T> *>::iterator it = _nav.begin(); it != _nav.end(); it++)
      (*it)->draw();
    for (std::list<EditText *>::iterator it = _editText.begin(); it != _editText.end(); it++)
      (*it)->draw();
  }

  void	up()
  {
    if (_eselected != _editText.end())
      return ;
    (*_selected)->setSelect(false);
    if (_selected == _nav.begin())
      _selected = _nav.end();
    _selected--;
    (*_selected)->setSelect(true);    
  }

  void	down()
  {
    if (_eselected != _editText.end())
      return ;
    (*_selected)->setSelect(false);
    _selected++;
    if (_selected == _nav.end())
      _selected = _nav.begin();
    (*_selected)->setSelect(true);
  }

  void	enter()
  {
    if (_editText.size() > 0 && _eselected != _editText.end())
      return ;
    if (_selected != _nav.end())
      {
	if ((*_selected)->isSave() == false)
	  {
	    _sound.play();
	    (*_selected)->enter();
	  }
	else
	  {
	    boost::property_tree::ptree _pt;

	    for (std::list<EditText *>::iterator it = _editText.begin(); it != _editText.end(); it++)
	      {
		_pt.add("Config." + (*it)->text, (*it)->_value);
	      }
	    write_ini((*_selected)->getInFile(), _pt);
	    _sound.play();
	    (*_selected)->enter();
	  }
      }
  }

  void	mouseMoved()
  {
    if (_eselected != _editText.end())
      return ;
    for (typename std::list<MenuSelect<T> *>::iterator it = _nav.begin(); it != _nav.end(); it++)
      if ((*it)->testMouse() == true)
	{
	  (*_selected)->setSelect(false);
	  _selected = it;
	  (*_selected)->setSelect(true);
	}
  }

  void	click()
  {
    bool	ok = false;

    for (typename std::list<MenuSelect<T> *>::iterator it = _nav.begin(); it != _nav.end(); it++)
      if ((*it)->testClick() == true)
	{
	  _sound.play();
	  this->enter();
	}
    for (std::list<EditText *>::iterator it = _editText.begin(); it != _editText.end(); it++)
      {
	if ((*it)->testClick() == true)
	  {
	    ok = true;
	    (*_selected)->setSelect(false);
	    if (_eselected != _editText.end())
	      (*_eselected)->setSelect(false);
	    _selected = _nav.end();
	    (*it)->setSelect(true);
	    _sound.play();
	    _eselected = it;
	  }
      }
    if (ok == false && _eselected != _editText.end())
      {
	_sound.play();
	(*_eselected)->setSelect(false);
	_eselected = _editText.end();
      }
  }

void	text()
{
  if (_eselected != _editText.end())
    {
      if (static_cast<int>(Event::instance().text.unicode) == 13)
	{
	  _sound.play();
	  (*_eselected)->setSelect(false);
	  _eselected = _editText.end();
	}
      else
	{
	  (*_eselected)->texte();
	}
    }
}
 
 void	push_back(MenuSelect<T> *add)
  {
    _nav.push_back(add);
    if (_nav.size() == 1)
      {
	(*_nav.begin())->setSelect(true);
	_selected = _nav.begin();
      }
  }

  void	push_back(EditText *editText)
  {
    _editText.push_back(new EditText(editText));
  }
private:
  std::list<MenuSelect<T> *>			_nav;
  std::list<EditText *>				_editText;
  typename std::list<MenuSelect<T> *>::iterator _selected;
  std::list<EditText *>::iterator		_eselected;
  sf::Sound					_sound;
};

#endif
