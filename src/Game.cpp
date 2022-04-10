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
    clear();
    start();
  }
};

Game::~Game() { 
  delete _screen;
  delete _player;
};

void Game::start() {
  // loop forever
  while(1) {
    _screen->print(_player);
    char ch = getch();
    bool quit = processInput(ch);
    if (quit) {
      break;
    }
  };
};

bool Game::processInput(char ch) {
  switch (ch) {
    case 'q':
    case 'Q':
      return TRUE;
    case 'a':
      break;
    case 'w':
      break;
    case 'd':
      break;
    case 's':
      break;
  };

  return FALSE;
};