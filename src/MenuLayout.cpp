#include "MenuLayout.hh"
#include "Screen.hh"

MenuLayout::MenuLayout(Screen *screen, const Layout &layout)
  : _screen(screen)
{
  for (std::list<sButton>::const_iterator it = layout.buttons.begin(); it != layout.buttons.end(); it++)
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
MenuLayout::draw()
{
  _menu.draw();
}
