#include "Screen.hh"
#include "MenuLayout.hh"

Screen::Screen()
  : _background("assets/textures/background.jpg")
{
  _layout = new MenuLayout;
}

Screen::~Screen()
{
}

void
Screen::down()
{
  _layout->down();
}

void
Screen::up()
{
  _layout->up();
}

void
Screen::enter()
{
  _layout->enter();
}

void
Screen::mouseMoved()
{
  _layout->mouseMoved();
}

void
Screen::draw()
{
  _background.draw();
  _layout->draw();
}
