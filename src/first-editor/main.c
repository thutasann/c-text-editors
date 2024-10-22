#include <ncurses.h>
#include <stdio.h>

void welcome_print(const char *message);

/**
    ## First Text Editor
 */
int main(void) {
    initscr(); // starting curse mode

    start_color();                          // start color functionality
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // (foreground, background)
    welcome_print("First Text Editor");

    raw();                // line buffering disabled
    keypad(stdscr, TRUE); // get F1, F2, etc...
    noecho();             // dont echo() while we do getch

    int ch = getch();

    while (ch != 'q') {
        printw("%c", ch);
        ch = getch();
    }

    refresh(); // print it on the real screen
    getch();
    endwin(); // end curse mode
    return 0;
}
