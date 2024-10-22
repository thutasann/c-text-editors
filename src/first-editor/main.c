#include <ncurses.h>
#include <stdio.h>

void welcome_text(const char *message);

int main(void) {
    welcome_text("First Editor");
    initscr();
    printw("Hello World\n");
    refresh();
    getch();
    endwin();
    return 0;
}
