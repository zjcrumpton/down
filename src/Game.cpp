#include <Direction.hpp>
#include <Game.hpp>
#include <GameText.hpp>
#include <Utility.hpp>
#include <ncurses.h>
#include <utility>

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
  delete _activeLevel;
};

void Game::start() {
  _activeLevel->add(std::make_pair(10, 10), &STONE_WALL);
  _activeLevel->add(std::make_pair(20, 20), &STONE_WALL);
  _activeLevel->add(std::make_pair(15, 15), &STONE_WALL);

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
  case 'Q': {
    return true;
  }
  case 'a': {
    Position newPos =
        std::make_pair(_player->pos().first - 1, _player->pos().second);
    if (!processCollision(&newPos)) {
      _screen->clearPos(_player->pos());
      _player->move(LEFT);
    }
    break;
  }
  case 'w': {
    Position newPos =
        std::make_pair(_player->pos().first, _player->pos().second - 1);

    if (!processCollision(&newPos)) {
      _screen->clearPos(_player->pos());
      _player->move(UP);
    }

    break;
  }
  case 'd': {
    Position newPos =
        std::make_pair(_player->pos().first + 1, _player->pos().second);

    if (!processCollision(&newPos)) {
      _screen->clearPos(_player->pos());
      _player->move(RIGHT);
    }

    break;
  }

  case 's': {
    Position newPos =
        std::make_pair(_player->pos().first, _player->pos().second + 1);

    if (!processCollision(&newPos)) {
      _screen->clearPos(_player->pos());
      _player->move(DOWN);
    }
    break;
  }
  };

  return FALSE;
};

bool Game::processCollision(Position *pos) {
  std::string posString = stringifyPosition(*pos);
  TileMap tiles = _activeLevel->tiles();
  TileMap::iterator it = tiles.find(posString);

  // key was found
  if (it != tiles.end()) {
    return true;
  } else {
    return false;
  }
};
