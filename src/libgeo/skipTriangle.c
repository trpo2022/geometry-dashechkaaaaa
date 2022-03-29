#include "skipTriangle.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* skipTriangle(char* cursor, char* startcursor, char triangle[])
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

    if ((strncmp(triangle, startcursor, strlen(triangle)) == 0)
        && (len == strlen(triangle))) {
        return cursor;
    }
    return NULL;
}
