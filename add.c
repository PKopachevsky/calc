#include "stdio.h"
#include "add.h"

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

void add(char *op1, char *op2){
    char i = 0;
    char len1 = 0, len2 = 0;
    char c1 = 0, c2 = 0;
    while((c1 = op1[len1]) != '\0' || (c2 = op2[len2]) != '\0') {
        if (c1 != '\0') {
            len1++;
        }
        if (c2 != '\0') {
            len2++;
        }
    }

    char summ, r = 0;
    while (i < len1 || i < len2) {
        c1 = (char) ((i < len1) ? op1[i] : '0');
        c2 = (char) ((i < len2) ? op2[i] : '0');
        summ = (char) (r + c1 + c2 - '0');
        if (summ > '9') {
            r = 1;
            summ -= 10;
        } else{
            r = 0;
        };
        op1[i++] = summ;
    }
    return;
}