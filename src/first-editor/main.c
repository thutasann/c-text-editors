#include "myenums.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

// ----- defines
#define ctrl(x) ((x) & 0x1f)
#define ESCAPE 27

// ----- methods
void welcome_print(const char *message);
void initializations(void);
char *stringify_mode();
void outro(void);

/** mode */
Mode mode = NORMAL;
int QUIT = 0;

/** text editor main function 🚀 */
int main(void) {
    // ----- initializations
    initializations();

    // ----- buffer
    char *buf = malloc(sizeof(char) * 1024);
    size_t buf_s = 0;

    // ----- pointer position
    int row, col;
    getmaxyx(stdscr, row, col);
    mvprintw(row - 1, 0, stringify_mode());
    move(0, 0);

    // ----- get characters
    int ch = 0;
    int x, y = 0;
    getyx(stdscr, y, x);

    // ----- print characters depending on the mode
    while (ch != ctrl('q') && QUIT != 1) {
        refresh();
        mvprintw(row - 1, 0, stringify_mode());
        move(y, x);
        ch = getch();

        // NORMAL or INSERT
        switch (mode) {
        case NORMAL:
            if (ch == 'i') {
                mode = INSERT;
            } else if (ch == ctrl('s')) { // save
                FILE *file = fopen("out.txt", "w");
                fwrite(buf, buf_s, 1, file);
                fclose(file);
                QUIT = 1;
            }
            break;
        case INSERT:
            keypad(stdscr, FALSE);
            if (ch == 127 || ch == KEY_BACKSPACE) { // backspace
                getyx(stdscr, y, x);
                move(y, x - 1);
                delch();
                buf[buf_s--] = ' ';
            } else if (ch == ESCAPE) { // escape
                mode = NORMAL;
                keypad(stdscr, TRUE);
            } else if (ch == ctrl('q')) {
                printw("CTRL + q\n");
                break;
            } else {
                buf[buf_s++] = ch;
                addch(ch);
            }
            break;
        default:
            break;
        }
        getyx(stdscr, y, x);
    }

    // ----- outros
    outro();

    return 0;
}

/** @private stringify mode */
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