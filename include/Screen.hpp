#pragma once
#include <Components.hpp>
#include <Player.hpp>
#include <Tile.hpp>
#include <Level.hpp>
#include <Utility.hpp>
#include <ncurses.h>

class Screen {
public:
  // Initialize NCurses
  Screen();
  // Clean up NCurses memory and end curses mode
  ~Screen();
  // Print player to the screen at position
  void print(Player *player) {
    Position pos = player->pos();
    Appearance style = player->style();

    attron(COLOR_PAIR(style.color));
    mvaddch(pos.second, pos.first, style.symbol);
    attroff(COLOR_PAIR(style.color));
  };

  // print msg to the screen
  void print(char *msg) {
    printw(msg); // Print to the virtual screen
    refresh();   // Print to the real screen
  };

  // print the level terrain to the screen
  void print(Level *level) {
    TileMap tiles = level->tiles();
    TileMap::iterator it = tiles.begin();

    while (it != tiles.end()) {
      Tile tile = it->second;
      Terrain terrain = *tile.terrain();
      Appearance style = terrain.style;
      Position pos = parsePosition(it->first);

      attron(COLOR_PAIR(style.color));
      mvaddch(pos.second, pos.first, style.symbol);
      attroff(COLOR_PAIR(style.color));

      it++;
    };
  };

  void clearPos(Position pos);

private:
  // Create color pairs
  void initColors();
};
