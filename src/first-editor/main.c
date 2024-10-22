#include <ncurses.h>
#include <stdio.h>

int main(void) {
    initscr();
    printw("Hello World\n");
    refresh();
    getch();
    endwin();
    return 0;
}
