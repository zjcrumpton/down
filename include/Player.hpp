#pragma once
#include <Components.hpp>

class Player {
public:
  Player(int x, int y);
  // Getters
  Position &pos();
  Appearance &style();
private:
  Position _pos;
  Appearance _style;
};
