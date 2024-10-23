#include "myenums.h"
#include <ncurses.h>
#include <stdio.h>

// defines
#define ctrl(x) ((x) & 0x1f)

// methods
void welcome_print(const char *message);
void initializations(void);
char *stringify_mode();

/** Mode */
Mode mode = NORMAL;

/**
    ## First Text Editor
 */
int main(void) {
    initializations();

    // ----- pointer position
    int row, col;
    getmaxyx(stdscr, row, col);
    mvprintw(row - 1, 0, stringify_mode());
    move(0, 0);

    // ----- get characters
    int ch = getch();
    addch(ch);

    int x, y = 0;
    getyx(stdscr, y, x);
    while (ch != 'q') {
        mvprintw(row - 1, 0, stringify_mode());
        move(y, x);

        ch = getch();
        if (ch == 127 || ch == KEY_BACKSPACE) { // backspace
            getyx(stdscr, y, x);
            move(y, x - 1);
            delch();
        } else if (ch == ctrl('q')) {
            printw("CTRL + q\n");
            break;
        } else {
            addch(ch);
        }
        getyx(stdscr, y, x);
    }

    refresh(); // print it on the real screen
    endwin();  // end curse mode

    return 0;
}

/** Stringify Mode */
char *stringify_mode() {
    switch (mode) {
    case NORMAL:
        return "NORMAL";
        break;
    case INSERT:
        return "INSERT";
        break;
    }
    return "NORMAL";
}