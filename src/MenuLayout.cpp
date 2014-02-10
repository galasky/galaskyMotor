#include "MenuLayout.hh"

MenuLayout::MenuLayout()
{
  _menu.push_back(new MenuSelect<MenuLayout>(this, &MenuLayout::createGame, "Create game", sf::Vector2f(100, 300), 100));
  _menu.push_back(new MenuSelect<MenuLayout>(this, &MenuLayout::nothing, "Menu", sf::Vector2f(100, 500), 100));
  _menu.push_back(new MenuSelect<MenuLayout>(this, &MenuLayout::nothing, "Option", sf::Vector2f(100, 400), 100));
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
MenuLayout::createGame()
{
  
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
