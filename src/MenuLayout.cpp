#include "MenuLayout.hh"
#include "Screen.hh"

MenuLayout::MenuLayout(Screen *screen, Layout &layout)
  : _menu(layout.soundButton),
    _screen(screen),
    _background(layout.background)
{
  for (std::list<sButton>::const_iterator it = layout.buttons.begin(); it != layout.buttons.end(); it++)
    {
      _menu.push_back(new MenuSelect<Screen>(_screen, &Screen::toLayout, *it));
    }
  for (std::list<EditText *>::iterator it = layout.edit_text.begin(); it != layout.edit_text.end(); it++)
    {
      _menu.push_back(*it);
    }
  for (std::list<sButton>::const_iterator it = layout.save.begin(); it != layout.save.end(); it++)
    {
      _menu.push_back(new MenuSelect<Screen>(_screen, &Screen::toLayout, *it));
    }
}

MenuLayout::~MenuLayout()
{

}

void
MenuLayout::nothing()
{
}

void
MenuLayout::down()
{
  _menu.down();
}

void
MenuLayout::up()
{
  _menu.up();
}

void
MenuLayout::enter()
{
  _menu.enter();
}

void
MenuLayout::mouseMoved()
{
  _menu.mouseMoved();
}

void
MenuLayout::click()
{
  _menu.click();
}

void
MenuLayout::text()
{
  _menu.text();
}

void
MenuLayout::draw()
{
  _background.draw();
  _menu.draw();
}
