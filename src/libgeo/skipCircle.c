#include "skipCircle.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* skipCircle(char* cursor, char* startcursor, char circle[])
{
    int len = 0;

    while (*startcursor == ' ') {
        startcursor++;
        cursor++;
    }

    while (isalpha(*cursor) != 0) {
        len++;
        cursor++;
    }

    if ((strncmp(circle, startcursor, strlen(circle)) == 0)) {
        if (len_circle == len) {
            return cursor;
        }
    }

    return NULL;
}
