#include <Utility.hpp>
#include <Components.hpp>
#include <utility>
#include <string>
#include <sstream>

Position parsePosition(std::string posString) {
  Position pos;
  std::stringstream ss(posString);

  while( ss.good() )
  {
    std::string substr;
    std::getline( ss, substr, ',' );
    int coord = std::stoi(substr);
    if (pos.first) {
      pos.second = coord;
    } else {
      pos.first = coord;
    }
  }

  return pos;
};
