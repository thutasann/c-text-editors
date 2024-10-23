#include <ncurses.h>
#include <stdio.h>

/**
 ## Initial Print Positions
 */
void print_positions(void) {
    int row, col;
    getmaxyx(stdscr, row, col);

    mvprintw(row - 1, 0, "NORMAL");
    move(0, 0);
}