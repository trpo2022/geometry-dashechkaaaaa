#include "skipCircle.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535
#define len_circle 6

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
