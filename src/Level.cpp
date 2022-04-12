#include <Level.hpp>

Level::Level() {
};

Level::~Level() {
};

void Level::add(Position p, Terrain *t) {
  char buffer [10];
  sprintf(buffer, "%d,%d", p.first, p.second);
  Tile newTile(t);
  std::pair<std::string, Tile> tilePair = std::make_pair(buffer, newTile);
  
  _tiles.insert(tilePair);
};

TileMap Level::tiles() {
  return _tiles;
};
