#include <stdio.h>
#include "parse.h"
#include "calc.h"
#include "reverse.h"

void main() {
    char input[256] = "1234567876543212345678764 + 1111111111111111111111111";
    char expr[256];
    parse(input, expr);

    char *result = calc(expr);
    reverse(result);

    char c, i = 0;
    while((c = result[i++]) != '\0') {
        printf("%c", c);
    }
}