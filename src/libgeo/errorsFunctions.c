#include "libgeo/errorsFunctions.h"
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
#include <stdio.h>
#include <stdlib.h>
char* parseCircle(
        char* cursor,
        char* startcursor,
        char circle[],
        double* x,
        double* y,
        double* radius)
{
    if ((cursor = skipCircle(cursor, startcursor, circle)) == NULL) {
        printf("The name of the figure is entered incorrectly: expected "
               "'circle'\n");
        _Exit(EXIT_FAILURE);
    }
    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("The character is entered incorrectly: expected '('\n");
        _Exit(EXIT_FAILURE);
    }
    if ((cursor = skipDigit(cursor, &x)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &y)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &radius)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if (radius <= 0) {
        printf("The radius cannot be negative or equal to zero");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("The character is entered incorrectly: expected ')'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = checkEndStr(cursor)) == NULL) {
        printf("An unexpected token at the end of a line\n");
        _Exit(EXIT_FAILURE);
    }

    return cursor;
}

char* parseTriangle(
        char* cursor,
        char* startcursor,
        char triangle[],
        double* x1,
        double* y1,
        double* x2,
        double* y2,
        double* x3,
        double* y3,
        double* x4,
        double* y4)
{
    if ((cursor = skipTriangle(cursor, startcursor, triangle)) == NULL) {
        printf("The name of the figure is entered incorrectly: expected "
               "'triangle'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("The character is entered incorrectly: expected '(('\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("The character is entered incorrectly: expected '(('\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &x1)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &y1)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &x2)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &y2)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &x3)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &y3)) == NULL) {
        printf("Wrong digit entered: expected '<double>'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("The character is entered incorrectly: expected ','\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipDigit(cursor, &x4)) == NULL) {
        printf("Wrong digit entered: expected '<double>', equal to the first "
               "point X\n");
        _Exit(EXIT_FAILURE);
    }
    if ((cursor = skipDigit(cursor, &y4)) == NULL) {
        printf("Wrong digit entered: expected '<double>', equal to the first "
               "point Y\n");
        _Exit(EXIT_FAILURE);
    }

    if ((*x1 != *x4) || (*y1 != *y4)) {
        printf("The start point should be equal to the end point: x1, y1: "
               "expected to be equal to x4, y4\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("The character is entered incorrectly: expected '))'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("The character is entered incorrectly: expected '))'\n");
        _Exit(EXIT_FAILURE);
    }

    if ((cursor = checkEndStr(cursor)) == NULL) {
        printf("An unexpected token at the end of a line\n");
        _Exit(EXIT_FAILURE);
    }

    return cursor;
}

void validTriangle(double a, double b, double c)
{
    if ((correctTriangle(&a, &b, &c)) == false) {
        printf("Such a triangle does not exist\n");
        _Exit(EXIT_FAILURE);
    }
}
