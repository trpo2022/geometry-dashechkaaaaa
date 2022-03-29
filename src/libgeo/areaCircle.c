#include "areaCircle.h"
#include <math.h>

#define _USE_MATH_DEFINES

double areaCircle(double radius)
{
    double circleA = 2 * M_PI * pow(radius, 2);
    return circleA;
}
