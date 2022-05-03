#include "libgeo/checkIntersection.h"
#include <ctest.h>
#include <libgeo/areaCircle.h>
#include <libgeo/areaTriangle.h>
#include <libgeo/checkEndStr.h>
#include <libgeo/correctTriangle.h>
#include <libgeo/errorsFunctions.h>
#include <libgeo/perimeterCircle.h>
#include <libgeo/perimeterTriangle.h>
#include <libgeo/sidesTriangle.h>
#include <libgeo/skipCircle.h>
#include <libgeo/skipDigit.h>
#include <libgeo/skipSign.h>
#include <libgeo/skipTriangle.h>
#include <stdio.h>

CTEST(geometry_suite, simple_intersection_0)
{
    const int exp = 0;
    double a = 5, b = 3, c = 2, radius = 5;
    int res = intersection(a, b, c, radius);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_intersection_1)
{
    const int exp = 1;
    double a = 8, b = 10, c = 12, radius = 2;
    int res = intersection(a, b, c, radius);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_circle_area)
{
    const double exp = 78.539816339744830961566084581988;
    double radius = 5;
    double res = areaCircle(radius);
    ASSERT_DBL_NEAR(exp, res);
}

CTEST(geometry_suite, simple_circle_perimetr)
{
    const double exp = 31.415926535897932384626433832795;
    double radius = 5;
    double res = perimeterCircle(radius);
    ASSERT_DBL_NEAR(exp, res);
}

CTEST(geometry_suite, simple_triangle_area)
{
    const int exp = 15;
    double x1 = 1, y1 = -2, x2 = 1, y2 = 4, x3 = 7, y3 = -2, a, b, c;
    sidesTriangle(x1, y1, x2, y2, x3, y3, &a, &b, &c);
    int triangleP = (a + b + c) / 2;
    int res = areaTriangle(a, b, c, triangleP);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_triangle_sides)
{
    const int exp = 1;
    double x1 = 90, y1 = -80, x2 = 1, y2 = 4, x3 = 7, y3 = -2, a, b, c, res = 0;
    sidesTriangle(x1, y1, x2, y2, x3, y3, &a, &b, &c);
    if (correctTriangle(&a, &b, &c)) {
        res = 1;
    }
    ASSERT_EQUAL(exp, res);
}
