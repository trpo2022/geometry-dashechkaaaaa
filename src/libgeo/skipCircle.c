#include "skipCircle.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* skipCircle(char* cursor, char* startcursor, char circle[])
{
    long unsigned int len = 0;

    while (*startcursor == ' ') {
        startcursor++;
        cursor++;
    }

    while (isalpha(*cursor) != 0) {
        len++;
        cursor++;
    }

    if ((strncmp(circle, startcursor, strlen(circle)) == 0)
        && (len == strlen(circle))) {
        return cursor;
    }

    return NULL;
}
