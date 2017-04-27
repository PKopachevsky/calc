#include "mult.h"
#include "add.h"
#include "../utils/alloc.h"

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

void mult(char *op1, char *op2) {
    char *result = alloc(256);
    char *prod = alloc(256);
    char c1, c2, v, r;
    char i1 = 0, i2, pp;
    result[0] = '0';
    result[1] = '\0';

    while ((c1 = op1[i1++]) != '\0') {
        i2 = 0;
        r = 0;
        pp = 0;
        for (char j = 1; j < i1; j++) {
            prod[pp++] = '0';
        }
        while ((c2 = op2[i2++]) != '\0') {
            v = (char) (r + (c1 - '0') * (c2 - '0'));
            if (v > 9) {
                prod[pp++] = '0' + (char) (v % 10);
                r = (char) (v / 10);
            } else {
                prod[pp++] = '0' + v;
                r = 0;
            };
        }
        if (r > 0) {
            prod[pp++] = '0' + r;
            prod[pp] = '\0';
        }
        add(result, prod);
    }

    i1 = 0;
    do {
        op1[i1] = (c1 = result[i1++]);
    } while (c1 != '\0');
}