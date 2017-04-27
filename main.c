#include <stdio.h>
#include <memory.h>
#include "calc.h"
#include "utils/reverse.h"
#include "utils/alloc.h"
#include "utils/parse.h"

#define EXIT "exit"

void main(int argc, char *argv[]) {
    char *input = alloc(256);;
    if (argc < 2) {
        scanf("%[^\n]%*c", input);
    } else {
        strcpy(input, argv[1]);
    };
    while (strcmp(input, EXIT)) {
        char *result = calc(parse(input));
        reverse(result);
        printf("%s\n", result);
        scanf("%[^\n]%*c", input);
    }
}