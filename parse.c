#include "parse.h"

#define MAX_LENGTH 100

char getPriority(char c);

void parse(char *expr, char *output) {
    char stack[MAX_LENGTH];

    char i=0, sp = 0, op = 0;

    char c, st, prior, dp = 0;
    char *digit;

    while((c = expr[i++]) != '\0') {
        if (c >= '0' && c <= '9') {
            output[op++] = c;
            digit = 1;
        } else {
            if(digit) {
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
    while (sp > 0) {
        output[op++] = stack[--sp];
        output[op++] = ' ';
    }
    output[op] = '\0';
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