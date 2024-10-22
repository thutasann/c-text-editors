#include <ncurses.h>
#include <stdio.h>

/**
    ## First Text Editor
 */
int main(void) {
    initscr();            // starting curse mode
    raw();                // line buffering disabled
    keypad(stdscr, TRUE); // get F1, F2, etc...
    noecho();             // dont echo() while we do getch

    int ch = getch();

    printw("%d\n", ch);
    while (ch != 'q') {
        ch = getch();
        printw("%c", ch);
    }

    refresh(); // print it on the real screen
    getch();
    endwin(); // end curse mode
    return 0;
}
