#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void welcome_text(void);
void read_keypress(void);
void enable_raw_mode(void);

/**
    ## Building own text editor named `Elastrix` in C
 */
int main(void) {
    welcome_text();
    enable_raw_mode();
    read_keypress();
    return 0;
}