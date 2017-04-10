#include "stdio.h"
#include "add.h"

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

char *add(char *op1, char *op2){
    char i1 = 0, i2 = 0;
    char c1 = 0, c2 = 0;
    while((c1 = op1[i1]) != '\0' || (c2 = op2[i2]) != '\0') {
        if (c1 != '\0') {
            i1++;
        }
        if (c2 != '\0') {
            i2++;
        }
    }

    char i = max(i1, i2) + 1;
    char result[i + 1];
    char summ, r = 0;
    result[i--] = '\0';
    while (i1 > 0 || i2 > 0) {
        c1 = (char) ((--i1 >= 0) ? op1[i1] : '0');
        c2 = (char) ((--i2 >= 0) ? op2[i2] : '0');
        summ = (char) (r + c1 + c2 - '0');
        if (summ > '9') {
            r = 1;
            summ -= 10;
        } else{
            r = 0;
        };
        result[i--] = summ;
    }
    char *x = (result + i + 1);
    return x;
}