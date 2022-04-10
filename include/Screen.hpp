#pragma once

class Screen {
public:
  // Initialize NCurses
  Screen();
  // Clean up NCurses memory and end curses mode
  ~Screen();

  // Print to the screen
  void print(char *msg);
};