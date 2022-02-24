#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

char* skipCircle(char* cursor, char* startcursor, char circle[])
{
    int len = 0;

    while (*startcursor == ' ') {
        startcursor++;
        cursor++;
    }

    while (isalpha(*cursor) != 0) {
        len++;
        cursor++;
    }

    if ((strncmp(circle, startcursor, strlen(circle)) == 0)
        && (len == strlen(circle))) {
        return cursor;
    }

    return NULL;
}

int main()
{
    char str[SIZE];
    char* cursor = str;
    char* startcursor = str;
    char circle[] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};

    fgets(str, SIZE, stdin);

    if ((cursor = skipCircle(cursor, startcursor, circle)) == NULL) {
        printf("The name of the figure is entered incorrectly: expected "
               "'circle'\n");
        return -1;
    }
    return 0;
}