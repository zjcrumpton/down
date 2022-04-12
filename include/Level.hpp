#pragma once
#include <Tile.hpp>
#include <unordered_map>
#include <string>
#include <Components.hpp>

using TileMap = std::unordered_map<std::string, Tile>;

class Level {
public:
  Level();
  ~Level();

  // add a new tile to the tilemap
  void add(Position p, Terrain *t);

  // Getters
  TileMap tiles();

private:
  TileMap _tiles = {};
};
