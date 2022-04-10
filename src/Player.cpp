#include <Player.hpp>
#include <Symbols.hpp>
#include <Colors.hpp>
#include <Components.hpp>

Player::Player(int x, int y) {
  _pos.x = x;
  _pos.y = y;
  _style.color = Colors::PLAYER;
  _style.symbol = Symbols::PLAYER;
};

Position &Player::pos() {
  return _pos;
};

Appearance &Player::style() {
  return _style;
};
