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
Screen::draw()
{
  _background.draw();
  _layout->draw();
}
