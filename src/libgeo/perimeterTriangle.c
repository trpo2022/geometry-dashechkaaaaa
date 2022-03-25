#include "perimeterTriangle.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

void perimeterTriangle(double a, double b, double c, double *triangleP)
{
    *triangleP = (a + b + c) / 2;
}
