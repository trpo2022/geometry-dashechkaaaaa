#include "intersection.h"
#include <stdbool.h>

bool intersection(double a, double b, double c, double radius)
{
    if (((a > radius) && (b > radius) && (c > radius))
        || ((a < radius) && (b < radius) && (c < radius))) {
        return true;
    } else {
        return false;
    }
}