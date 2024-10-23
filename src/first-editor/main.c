#include "myenums.h"
#include <ncurses.h>
#include <stdio.h>

// defines
#define ctrl(x) ((x) & 0x1f)

// methods
void welcome_print(const char *message);
void initializations(void);
void print_positions(void);

/** Mode */
Mode mode = NORMAL;

/**
    ## First Text Editor
 */
int main(void) {
    initializations();
    print_positions();

    int ch = getch();
    addch(ch);

    while (ch != 'q') {
        ch = getch();
        if (ch == 127 || ch == KEY_BACKSPACE) { // backspace
            int x, y;
            getyx(stdscr, y, x);

            if (x > 0) {
                move(y, x - 1);
                delch();
            }
        } else if (ch == ctrl('q')) {
            printw("CTRL + q\n");
            break;
        } else {
            addch(ch);
        }
    }

    refresh(); // print it on the real screen
    getch();   // get character
    endwin();  // end curse mode

    return 0;
}
