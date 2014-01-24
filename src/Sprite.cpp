#include "Sprite.hh"
#include "Window.hpp"

Sprite::Sprite(const std::string &path)
{
  _texture.loadFromFile(path);
  _sprite.setTexture(_texture);
}

Sprite::~Sprite()
{

}

void
Sprite::animate()
{

}

void
Sprite::draw()
{
  Window::instance().draw(_sprite);
}
