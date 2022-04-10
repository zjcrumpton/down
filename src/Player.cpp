#include <Colors.hpp>
#include <Components.hpp>
#include <Direction.hpp>
#include <Player.hpp>
#include <Symbols.hpp>

Player::Player(int x, int y) {
  _pos.x = x;
  _pos.y = y;
  _style.color = Colors::PLAYER;
  _style.symbol = Symbols::PLAYER;
};

void Player::move(Direction d) {
  switch (d) {
  case LEFT:
    _pos.x--;
    break;
  case RIGHT:
    _pos.x++;
    break;
  case UP:
    _pos.y--;
    break;
  case DOWN:
    _pos.y++;
    break;
  };
};

Position &Player::pos() { return _pos; };

Appearance &Player::style() { return _style; };
