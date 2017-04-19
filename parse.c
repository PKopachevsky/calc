#include "alloc.h"

#define MAX_LENGTH 100

char getPriority(char c);

char *parse(char *expr) {
    char *output = alloc(256);
    char stack[MAX_LENGTH];

    char i=0, sp = 0, op = 0;

    char c, st, prior, dp = 0;
    char *digit;

    while((c = expr[i++]) != '\0') {
        if (c >= '0' && c <= '9') {
            if(dp == 0) {
                digit = alloc(50);
            }
            digit[dp++] = c;
        } else {
            if(dp > 0) {
                while(dp > 0) {
                    output[op++] = digit[--dp];
                }
                output[op++] = ' ';
            }
            switch(c) {
                case '*':
                case '/':
                case '+':
                case '-':
                    if (sp == 0) {
                        stack[sp++] = c;
                    } else {
                        prior = getPriority(c);
                        while (--sp >= 0 && prior <= getPriority((st = stack[sp]))) {
                            output[op++] = st;
                            output[op++] = ' ';
                        }
                        sp++;
                        stack[sp++] = c;
                    }
                    break;
                case '(':
                    stack[sp++] = c;
                    break;
                case ')':
                    while((c = stack[--sp])!='(') {
                        output[op++] = c;
                        output[op++] = ' ';
                    }
            }
        }
    }
    while(dp > 0) {
        output[op++] = digit[--dp];
    }
    output[op++] = ' ';
    while (sp > 0) {
        output[op++] = stack[--sp];
        output[op++] = ' ';
    }
    output[op] = '\0';

    return output;
}

char getPriority(char c) {
    switch(c) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}