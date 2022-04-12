#include <Level.hpp>
#include <Utility.hpp>

Level::Level(){};

Level::~Level(){};

void Level::add(Position p, Terrain *t) {
  Tile newTile(t);
  std::string posString = stringifyPosition(p);
  std::pair<std::string, Tile> tilePair = std::make_pair(posString, newTile);

  _tiles.insert(tilePair);
};

TileMap Level::tiles() { return _tiles; };
