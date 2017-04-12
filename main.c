#include <stdio.h>
#include "parse.h"
#include "calc.h"
#include "reverse.h"

void main() {
    char input[100] = "1234 + 1111";
    char expr[100];
    parse(input, expr);

    char *result = calc(expr);
    reverse(result);

    char c, i = 0;
    while((c = result[i++]) != '\0') {
        putchar(c);
    }
}