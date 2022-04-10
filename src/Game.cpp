#include <Game.hpp>
#include <GameText.hpp>
#include <ncurses.h>

Game::Game() {
  _screen = new Screen();
  _screen->print(GameText::WELCOME_MSG);
  char c = getch();

  if (c == 'q' || c == 'Q') {
    _screen->print("Goodbye!");
  } else {
    start();
  }
};

Game::~Game() { delete _screen; };

void Game::start() { _screen->print("Game Started!"); };
