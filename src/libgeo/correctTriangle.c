#include "correctTriangle.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

bool correctTriangle(double a, double b, double c)
{
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        return true;
    } else {
        return false;
    }
}
