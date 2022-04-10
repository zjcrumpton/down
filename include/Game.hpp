#pragma once
#include <Player.hpp>
#include <Screen.hpp>

class Game {
public:
  // Welcome the player and prompt them to start the game loop
  Game();
  // Clean up memory
  ~Game();

private:
  Screen *_screen;
  Player *_player;

  // Start the main game loop
  void start();
  // Process player input. If function returns true, player has chosen to exit
  // the program.
  bool processInput(char ch);
};
