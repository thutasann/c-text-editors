#include <ncurses.h>
#include <stdio.h>

/**
    ## Outro Methods
 */
void outro(void) {
    refresh(); // print it on the real screen
    endwin();  // end curse mode
}