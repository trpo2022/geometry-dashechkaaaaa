#include "skipSign.h"
#include <stdlib.h>

char* skipSign(char* cursor, char sign)
{
    while (*cursor != sign) {
        if (*cursor == ' ') {
            cursor++;
        }

        return NULL;
    }

    if (*cursor == sign) {
        cursor++;
    }

    return cursor;
}
