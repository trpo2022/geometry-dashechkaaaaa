#include "libgeo/areaCircle.h"
#include "libgeo/areaTriangle.h"
#include "libgeo/checkEndStr.h"
#include "libgeo/correctTriangle.h"
#include "libgeo/perimeterCircle.h"
#include "libgeo/perimeterTriangle.h"
#include "libgeo/sidesTriangle.h"
#include "libgeo/skipCircle.h"
#include "libgeo/skipDigit.h"
#include "libgeo/skipSign.h"
#include "libgeo/skipTriangle.h"

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

int main()
{
    char str[SIZE];
    char* cursor = str;
    char* startcursor = str;
    char circle[] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};
    char triangle[] = {'t', 'r', 'i', 'a', 'n', 'g', 'l', 'e', '\0'};
    double a = 0, b = 0, c = 0, triangleP = 0, x1, y1, x2, y2, x3, y3, x4, y4,
           radius;

    printf("Enter circle data:\n");

    fgets(str, SIZE, stdin);

    if ((cursor = skipCircle(cursor, startcursor, circle)) == NULL) {
        printf("The name of the figure is entered incorrectly: expected "
               "'circle'\n");
        return -1;
    }

    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("The character is entered incorrectly: expected '('\n");
        return -2;
    }

    if ((cursor = skipDigit(cursor, &x1)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -3;
    }

    if ((cursor = skipDigit(cursor, &y1)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -4;
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        return -5;
    }

    if ((cursor = skipDigit(cursor, &radius)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -6;
    }

    if (radius <= 0) {
        printf("The radius cannot be negative or equal 0\n");
        return -7;
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("The character is entered incorrectly: expected ')'\n");
        return -8;
    }

    if ((cursor = checkEndStr(cursor)) == NULL) {
        printf("An unexpected token at the end of a line\n");
        return -9;
    }

    perimeterCircle(radius);
    areaCircle(radius);

    printf("\nFigure name: %s\n", circle);
    printf("x = %lf\n", x1);
    printf("y = %lf\n", y1);
    printf("radius = %lf\n", radius);
    printf("perimeter = %lf \n", perimeterCircle(radius));
    printf("area = %lf\n \n", areaCircle(radius));

    printf("Enter triangle data:\n");

    fgets(str, SIZE, stdin);
    cursor = str;

    if ((cursor = skipTriangle(cursor, startcursor, triangle)) == false) {
        printf("The name of the figure is entered incorrectly: expected "
               "'triangle'\n");
        return -10;
    }

    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("The character is entered incorrectly: expected '(('\n");
        return -11;
    }

    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("The character is entered incorrectly: expected '(('\n");
        return -12;
    }

    if ((cursor = skipDigit(cursor, &x1)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -13;
    }

    if ((cursor = skipDigit(cursor, &y1)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -14;
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        return -15;
    }

    if ((cursor = skipDigit(cursor, &x2)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -16;
    }

    if ((cursor = skipDigit(cursor, &y2)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -17;
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        return -18;
    }

    if ((cursor = skipDigit(cursor, &x3)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -19;
    }

    if ((cursor = skipDigit(cursor, &y3)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        return -20;
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        return -21;
    }

    if ((cursor = skipDigit(cursor, &x4)) == NULL) {
        printf("Wrong digit entered: expected '<double>', equal to the first "
               "point X\n");
        return -22;
    }

    if ((cursor = skipDigit(cursor, &y4)) == NULL) {
        printf("Wrong digit entered: expected '<double>', equal to the first "
               "point Y\n");
        return -23;
    }

    if (x1 != x4 && y1 != y4) {
        printf("The start point should be equal to the end point: x1, y1 were "
               "expected to be equal to x4, y4\n");
        return -24;
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("The character is entered incorrectly: expected '))'\n");
        return -25;
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("The character is entered incorrectly: expected '))'\n");
        return -26;
    }

    if ((cursor = checkEndStr(cursor)) == NULL) {
        printf("An unexpected token at the end of a line\n");
        return -27;
    }

    sidesTriangle(x1, y1, x2, y2, x3, y3, &a, &b, &c);

    if ((correctTriangle(a, b, c)) == false) {
        printf("Such a triangle does not exist\n");
        return -28;
    }

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

    return 0;
}
