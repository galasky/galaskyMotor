#include <iostream>
#include "Player.hh"

Player::Player()
{
  _button.addPressed(sf::Keyboard::Left, &APlayer::left);
  _button.addPressed(sf::Keyboard::Right, &APlayer::right);
}

Player::~Player()
{
}

void
Player::left()
{
  std::cout << "left" << std::endl;
}

void
Player::right()
{
  std::cout << "right" << std::endl;
}

void
Player::catch_event()
{
  _button.catch_event();
}
