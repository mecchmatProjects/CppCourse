/*
https://stackoverflow.com/questions/20959436/how-to-use-fgets-to-safely-handle-user-input-more-than-once

This function:

    can output a prompt if desired.
    uses fgets in a way that avoids buffer overflow.
    detects end-of-file during the input.
    detects if the line was too long, by detecting lack of newline at the end.
    removes the newline if there.
    "eats" characters until the next newline to ensure that they're not left in the input stream for the next call to this function.

???? - untested
*/

// Use stdio.h and string.h for C.
#include <stdio.h>
#include <string.h>

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2
static int getLine (char *prmpt, char *buff, size_t sz) {
    int ch, extra;

    // Output prompt then get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL)
        return NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    return OK;
}

