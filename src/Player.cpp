#include <Colors.hpp>
#include <Player.hpp>
#include <Symbols.hpp>

Player::Player(int x, int y) {
  _pos.first = x;
  _pos.second = y;
  _style.color = Colors::PLAYER;
  _style.symbol = Symbols::PLAYER;
};

void Player::move(Direction d) {
  switch (d) {
  case LEFT:
    _pos.first--;
    break;
  case RIGHT:
    _pos.first++;
    break;
  case UP:
    _pos.second--;
    break;
  case DOWN:
    _pos.second++;
    break;
  };
};

Position Player::pos() { return _pos; };

Appearance &Player::style() { return _style; };
