#pragma once
#include <Components.hpp>
#include <Tile.hpp>
#include <string>
#include <unordered_map>

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
