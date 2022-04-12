#pragma once
#include <Colors.hpp>
#include <utility>

struct Appearance {
  char symbol;
  ColorType color;
};

using Position = std::pair<int, int>;
