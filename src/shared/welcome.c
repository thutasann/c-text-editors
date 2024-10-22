#include <stdio.h>

/**
    ## Welcome Text
    - `\033[1;32m:` This is an ANSI escape sequence where:
    - `\033` is the escape character.
    - `1` makes the text bold or birght.
    - `32` sets the text color to green.
    - `\033[0m` Resets the text formatting back to the terminal's default.\

    ## Colors
    - 31: Red
    - 32: Green
    - 33: Yellow
    - 34: Blue
    - 35: Magenta
    - 36: Cyan
    - 37: White
 */
void welcome_text(const char *message) {
    // Apply bright green color, bold, and underline formatting for the heading
    printf("\033[1;32m");
    printf("%s\n", message);
    printf("\033[0m"); // Reset formatting to default
    printf("Press 'q' and 'enter' to exit.\n");
    printf("****************************\n");
}