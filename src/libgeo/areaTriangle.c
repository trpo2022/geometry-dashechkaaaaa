#include "areaTriangle.h"
#include <math.h>

double areaTriangle(double a, double b, double c, double triangleP)
{
    double triangleA = sqrt(
            triangleP * ((triangleP - a) * (triangleP - b) * (triangleP - c)));

    return triangleA;
}
