#include <Screen.hpp>
#include <ncurses.h>

Screen::Screen() {
  initscr(); // Start curses mode
  refresh(); // Print it on to the real screen
  endwin();  // End curses mode;
};

Screen::~Screen() {
  clear();
  endwin();
};

void Screen::print(char *msg) {
  printw(msg); // Print to the virtual screen
  refresh();   // Print to the real screen
};
