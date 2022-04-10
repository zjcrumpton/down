#pragma once
#include <Player.hpp>
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
    mvaddch(pos.y, pos.x, style.symbol);
    attroff(COLOR_PAIR(style.color));
  };

  // print msg to the screen
  void print(char *msg) {
    printw(msg); // Print to the virtual screen
    refresh();   // Print to the real screen
  };


private:
  // Create color pairs
  void initColors();
};
