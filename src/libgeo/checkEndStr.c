#include "checkEndStr.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

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
