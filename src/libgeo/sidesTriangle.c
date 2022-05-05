#include "sidesTriangle.h"
#include <math.h>

void sidesTriangle(
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3,
        double* a,
        double* b,
        double* c)
{
    *a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    *b = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    *c = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
}
