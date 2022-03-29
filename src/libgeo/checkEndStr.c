#include "checkEndStr.h"
#include <stdlib.h>

char* checkEndStr(char* cursor)
{
    while (*cursor != '\n') {
        if (*cursor == ' ') {
            cursor++;
        }
        return NULL;
    }

    return cursor;
}
