#include "skipTriangle.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535
#define len_triangle 8

char* skipTriangle(char* cursor, char* startcursor, char triangle[])
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

    if ((strncmp(triangle, startcursor, strlen(triangle)) == 0)) {
        if (len_triangle == len) {
            return cursor;
        }
    }
    return NULL;
}
