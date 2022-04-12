#include <Components.hpp>
#include <Tile.hpp>
#include <Utility.hpp>
#include <sstream>
#include <string>
#include <utility>

Position parsePosition(std::string posString) {
  Position pos;
  std::stringstream ss(posString);

  while (ss.good()) {
    std::string substr;
    std::getline(ss, substr, ',');
    int coord = std::stoi(substr);
    if (pos.first) {
      pos.second = coord;
    } else {
      pos.first = coord;
    }
  }

  return pos;
};

std::string stringifyPosition(Position pos) {
  char buffer[10];
  sprintf(buffer, "%d,%d", pos.first, pos.second);

  return buffer;
};
