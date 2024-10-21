#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

/**
    ## Read KeyPress
    - `STDIN_FILENO` is the default data stream for input from the command line, and its value is `0`.
    - File Descriptors (FD) are non-negative integers (0, 1, 2, ...) that are associated with files that are opened.
    - 0, 1, 2 are standard FD's that corresponds to `STDIN_FILENO`, `STDOUT_FILENO`, `STDERR_FILENO`
    - Each process which deals with a file (can say almost every process since everything is a file in Linux), has its own file descriptor (FD), which is unique per process.

    ### Read Method
    - `read()` attemps to read up to count bytes from the file descriptor fd into the buffer starting at buf.
    - `ssize_t read(int fd, void *buf, size_t count);`
    - `*buf` is a pointer to the variable which points to the variable's address space.
    - `count` accepts the number of bytes to the `*buf`.
    - `fd` is a file descriptor.

    ### Canonical mode vs Raw mode
    - In cooked (canonical) mode, the terminal's commands can be edited before executing it. We can use backspace and modify it all before executing the command, the computer won't know about it.
    - In Raw mode, the terminal send each character it gets in it to the computer. So, if we press backspace to edit strings, the computer knows about it.
 */
void read_keypress(void) {
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == 'q') {
            printf("Exiting...\n");
            exit(0);
        }
    };
}