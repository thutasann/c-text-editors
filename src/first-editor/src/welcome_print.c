#include <curses.h>

void welcome_print(const char *message) {
    // Apply bright green color and bold formatting for the heading
    attron(A_BOLD | COLOR_PAIR(1)); // Turn on bold and color pair 1
    printw("%s\n", message);
    attroff(A_BOLD | COLOR_PAIR(1)); // Turn off bold and color pair 1

    // Reset formatting and print the exit instructions
    printw("Press 'q' to exit.\n");
    printw("****************************\n");
}
