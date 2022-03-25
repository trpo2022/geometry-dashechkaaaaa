#include "skipDigit.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

char* skipDigit(char* cursor, double* digit)
{
    char* d;
    bool flag;

    while (isdigit(*cursor) == 0) {
        flag = false;
        if (*cursor == '-') {
            flag = true;
            cursor++;
        } else if (*cursor == ' ') {
            cursor++;
        } else {
            return NULL;
        }
    }

    if (isdigit(*cursor) != 0) {
        *digit = strtod(cursor, &d);
        if (flag != false) {
            *digit *= -1;
        }
        cursor = d;
    }

    return cursor;
}
