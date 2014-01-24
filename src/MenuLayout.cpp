#include "MenuLayout.hh"

MenuLayout::MenuLayout() :
  _start(this, &MenuLayout::nothing, "Start", sf::Vector2f(100, 100), 100)
{

}

MenuLayout::~MenuLayout()
{

}

void
MenuLayout::nothing()
{
}

void
MenuLayout::draw()
{
  _start.draw();
}
