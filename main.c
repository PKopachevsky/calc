#include <stdio.h>
#include "parse.h"
#include "calc.h"

void main() {
    char input[100] = "9999 + 1";
    char expr[100];
    parse(input, expr);

    char *result = calc(expr);

    char c, i = 0;
    while((c = result[i++]) != '\0') {
        putchar(c);
    }
}