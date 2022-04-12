#include <Direction.hpp>
#include <Game.hpp>
#include <GameText.hpp>
#include <ncurses.h>

Game::Game() {
  _activeLevel = new Level();
  _screen = new Screen();
  _screen->print(GameText::WELCOME_MSG);
  char c = getch();

  if (c == 'q' || c == 'Q') {
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
  _activeLevel->add(std::make_pair(10, 10), &STONE_WALL);
  _screen->print(_activeLevel);

  // loop forever
  while (1) {
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
    return true;
  case 'a':
    _screen->clearPos(_player->pos());
    _player->move(LEFT);
    break;
  case 'w':
    _screen->clearPos(_player->pos());
    _player->move(UP);
    break;
  case 'd':
    _screen->clearPos(_player->pos());
    _player->move(RIGHT);
    break;
  case 's':
    _screen->clearPos(_player->pos());
    _player->move(DOWN);
    break;
  };

  return FALSE;
};