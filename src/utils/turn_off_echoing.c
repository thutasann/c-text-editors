#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

/**
    ### Enable Raw Mode (Turn off echoing)
    We can set a terminal's attributes by
    - using `tcgetattr()` to read the current attributes into a struct
    - modifying the struct by hand
    - passing the modified struct to `tcsetattr()`
    - to write the new terminal attributes back out.

    ## tcgetattr()
    - the function shall get the parameters associated with the terminal referred to by fildes and
    - stores them in the termios structure referenced by termios_p.
    - the fildes argument is an open file descriptor associated with a terminal.
    - the `termios_p` argument is a pointer to a termios structure.
    - the `tggetattr()` operation is allowed from any process.
 */
void enable_raw_mode(void) {
    struct termios raw;

    // get current terminal attributes
    tcgetattr(STDIN_FILENO, &raw);

    // disable echo and canoncial mode
    // raw.c_lflag &= ~(ECHO);

    // set the new attribute
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
