#pragma once
#include <Components.hpp>
#include <Direction.hpp>

class Player {
public:
  Player(int x, int y);
  // Update the user's position
  void move(Direction d);
  // Getters
  Position &pos();
  Appearance &style();

private:
  Position _pos;
  Appearance _style;
};
