#include <ncurses.h>
#include <stdio.h>

void welcome_print(const char *message);

/**
    ## First Text Editor
 */
int main(void) {
    initscr();            // init
    raw();                // line buffering disabled
    keypad(stdscr, TRUE); // get F1, F2, etc...
    noecho();             // dont echo() while we do getch

    start_color();                          // start color functionality
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // (foreground, background)

    int row, col;
    getmaxyx(stdscr, row, col);

    mvprintw(row - 1, 0, "NORMAL");
    move(0, 0);

    int ch = getch();
    addch(ch);

    while (ch != 'q') {
        ch = getch();
        if (ch == 127) {
            int x, y;
            getyx(stdscr, y, x);
            move(y, x - 1);
            delch();
        } else {
            addch(ch);
        }
    }

    refresh(); // print it on the real screen
    getch();
    endwin(); // end curse mode
    return 0;
}
