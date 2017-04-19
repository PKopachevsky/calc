#include <stdio.h>
#include "parse.h"
#include "calc.h"
#include "reverse.h"

void main(int argc, char *argv[] ) {
    char *expr = parse(argv[1]);
    char *result = calc(expr);
    reverse(result);

    char c, i = 0;
    while((c = result[i++]) != '\0') {
        printf("%c", c);
    }
}