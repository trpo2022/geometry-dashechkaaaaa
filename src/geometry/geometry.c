#include "libgeo/areaCircle.h"
#include "libgeo/areaTriangle.h"
#include "libgeo/checkEndStr.h"
#include "libgeo/checkIntersection.h"
#include "libgeo/correctTriangle.h"
#include "libgeo/errorsFunctions.h"
#include "libgeo/perimeterCircle.h"
#include "libgeo/perimeterTriangle.h"
#include "libgeo/sidesTriangle.h"
#include "libgeo/skipCircle.h"
#include "libgeo/skipDigit.h"
#include "libgeo/skipSign.h"
#include "libgeo/skipTriangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main()
{
    char str[SIZE];
    char* cursor = str;
    char* startcursor = str;
    char circle[] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};
    char triangle[] = {'t', 'r', 'i', 'a', 'n', 'g', 'l', 'e', '\0'};
    double x = 0, y = 0, radius = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0,
           y3 = 0, x4 = 0, y4 = 0, a = 0, b = 0, c = 0, triangleP = 0;

    printf("Enter circle data:\n");
    fgets(str, SIZE, stdin);
    cursor = parseCircle(cursor, startcursor, circle, &x, &y, &radius);
    perimeterCircle(radius);
    areaCircle(radius);

    printf("\nFigure name: %s\n", circle);
    printf("x = %lf\n", x);
    printf("y = %lf\n", y);
    printf("radius = %lf\n", radius);
    printf("perimeter = %lf \n", perimeterCircle(radius));
    printf("area = %lf\n \n", areaCircle(radius));
    printf("Enter triangle data:\n");

    fgets(str, SIZE, stdin);
    cursor = str;
    cursor = parseTriangle(
            cursor,
            startcursor,
            triangle,
            &x1,
            &y1,
            &x2,
            &y2,
            &x3,
            &y3,
            &x4,
            &y4);
    sidesTriangle(x1, y1, x2, y2, x3, y3, &a, &b, &c);
    validTriangle(a, b, c);
    perimeterTriangle(a, b, c, &triangleP);
    areaTriangle(a, b, c, triangleP);
    printf("\nFigure name: %s\n", triangle);
    printf("x1 = %lf\n", x1);
    printf("y1 = %lf\n", y1);
    printf("a = %lf\n", a);
    printf("x2 = %lf\n", x2);
    printf("y2 = %lf\n", y2);
    printf("b = %lf\n", b);
    printf("x3 = %lf\n", x3);
    printf("y3 = %lf\n", y3);
    printf("c = %lf\n", c);
    printf("perimeter = %lf \n", triangleP);
    printf("area = %lf\n \n", areaTriangle(a, b, c, triangleP));
    if ((intersection(a, b, c, radius)) == 0) {
        printf("Figures do not intersect\n");
    } else {
        printf("Figures intersect\n");
    }

    return 0;
}
