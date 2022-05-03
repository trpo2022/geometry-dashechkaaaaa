#include "checkIntersection.h"

int intersection(double a, double b, double c, double radius)
{
    if (((a > radius) && (b > radius) && (c > radius))
        || ((a < radius) && (b < radius) && (c < radius))) {
        return 1;
    } else {
        return 0;
    }
}
