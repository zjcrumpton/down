#include <Components.hpp>
#include <Player.hpp>
#include <Screen.hpp>
#include <ncurses.h>

Screen::Screen() {
  initscr(); // Start curses mode
  raw(); // If raw() hasn't been called, user has to press enter to send char to
         // the program
  keypad(stdscr, TRUE); // get access to F1, F2 etc
  noecho(); // don't echo typed user input characters when calling getch() etc
  initColors();
};

Screen::~Screen() {
  clear();
  endwin();
};

void Screen::initColors() {
  start_color();
  init_pair(Colors::PLAYER, COLOR_BLUE, COLOR_BLACK);
};
