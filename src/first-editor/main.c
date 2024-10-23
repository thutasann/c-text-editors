#include <ncurses.h>
#include <stdio.h>

void welcome_print(const char *message);
void initializations(void);
void print_positions(void);

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
    getch();   // get character
    endwin();  // end curse mode

    return 0;
}
