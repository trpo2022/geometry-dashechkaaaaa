#include "areaTriangle.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

double areaTriangle(double a, double b, double c, double triangleP)
{
    double triangleA = sqrt(
            triangleP * ((triangleP - a) * (triangleP - b) * (triangleP - c)));

    return triangleA;
}
