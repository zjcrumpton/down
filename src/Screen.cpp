#include <Colors.hpp>
#include <Screen.hpp>
#include <Symbols.hpp>

Screen::Screen() {
  initscr(); // Start curses mode
  raw(); // If raw() hasn't been called, user has to press enter to send char to
         // the program
  keypad(stdscr, TRUE); // get access to F1, F2 etc
  noecho(); // don't echo typed user input characters when calling getch() etc
  curs_set(0); // hide the cursor
  initColors();
};

Screen::~Screen() {
  clear();
  endwin();
};

void Screen::initColors() {
  start_color();
  init_pair(Colors::PLAYER, COLOR_BLUE, COLOR_BLACK);
  init_pair(Colors::EMPTY, COLOR_BLACK, COLOR_BLACK);
};

void Screen::clearPos(Position &pos) {
  attron(COLOR_PAIR(Colors::EMPTY));
  mvaddch(pos.y, pos.x, Symbols::EMPTY);
  attroff(COLOR_PAIR(Colors::EMPTY));
};
