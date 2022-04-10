#include <Game.hpp>
#include <GameText.hpp>
#include <ncurses.h>

Game::Game() {
  _screen = new Screen();
  _screen->print(GameText::WELCOME_MSG);
  char c = getch();

  if (c == 'q' || c == 'Q') {
    _screen->print("Goodbye!");
    getch();
  } else {
    _player = new Player(0, 0);
    _screen->print(_player);

    start();
  }
};

Game::~Game() { 
  delete _screen;
  delete _player;
};

void Game::start() { 
  _screen->print("Game Started!");
  getch();
};
