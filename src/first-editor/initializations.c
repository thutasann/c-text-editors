#include <ncurses.h>
#include <stdio.h>

/**
    ## Initializations
 */
void initializations(void) {
    initscr();            // init
    raw();                // line buffering disabled
    keypad(stdscr, TRUE); // get F1, F2, etc...
    noecho();             // dont echo() while we do getch

    // start_color();                          // start color functionality
    // init_pair(1, COLOR_GREEN, COLOR_BLACK); // (foreground, background)
}