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
#include <string.h>



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



CTEST(parsing_suite, ParsingCircle)
{
    char enter[] = "circle(3 5, 4)\n";
    char* cursor = enter;
    char* startcursor = enter;
    char circle[] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};
    double x, y, radius;
    int exp = 0; 
    const int res = 1;
    if (parseCircle(cursor, startcursor, circle, &x, &y, &radius)){
    	exp = 1;
    }
    ASSERT_EQUAL(exp, res);

}


CTEST(parsing_suite, ParsingTriangle)
{

    char enter[] = "triangle((3 4, 5 5, 8 10, 3 4))\n";
    char* cursor = enter;
    char* startcursor = enter;

    char triangle[] = {'t', 'r', 'i', 'a', 'n', 'g', 'l', 'e', '\0'};
    double x1, y1, x2, y2, x3, y3, x4, y4;

    int exp = 0; 
    const int res = 1;
    if (parseTriangle(cursor, startcursor, triangle, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4)){
    	exp = 1;
    }
    ASSERT_EQUAL(exp, res);
}

