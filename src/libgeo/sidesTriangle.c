#include "sidesTriangle.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

void sidesTriangle(double x1, double y1, double x2, double y2, double x3, double y3, double *a, double *b, double *c)
{
    *a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    *b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    *c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
}
