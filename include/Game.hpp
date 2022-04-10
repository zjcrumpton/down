#pragma once
#include <Screen.hpp>

class Game {
public:
  // Welcome the player and prompt them to start the game loop
  Game();
  // Clean up memory
  ~Game();

private:
  Screen *_screen;

  // Start the main game loop
  void start();
};
