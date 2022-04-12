#include <Tile.hpp>

Tile::Tile(Terrain *t) {
  _terrain = t;
};

Terrain *Tile::terrain() {
  return _terrain;
};
