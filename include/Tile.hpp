#pragma once
#include <Terrain.hpp>

class Tile {
public:
  Tile(Terrain *t);

  // Getters
  Terrain *terrain();

private:
  Terrain *_terrain;
};
