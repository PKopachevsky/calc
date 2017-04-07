#include <stdio.h>
#include "parse.h"
#include "calc.h"
#include "alloc.h"

void parse(char *expr, char *output);

char *add(char *, char *);

char *alloc(int n);

void main() {
    char *operands[20];
    char *operand, *op1, *op2, *result;

    char op = 0, ocp = 0, op_len = 0;

    char input[100] = "34543 + 7545 + 567 + 366 + 34 + 40 + 6 + 444";
    char expr[100];

    parse(input, expr);

    char c;
    int i = 0;

    printf("%s\n", expr);
    do {
        c = expr[i++];
        while (c >= '0' && c <= '9') {
            if (ocp == 0) {
                if(op == op_len) {
                    operand = alloc(50);
                    operands[op++] = operand;
                    op_len++;
                } else {
                    op++;
                }
            }
            operand[ocp++] = c;
            c = expr[i++];
        }
        if (ocp > 0) {
            operand[ocp] = '\0';
            ocp = 0;
        }
        if (c != ' ') {
            op1 = operands[--op];
            op2 = operands[--op];
            switch (c) {
                case '+':
                    result = add(op1, op2);
                    operands[op++] = result;
                    break;

                    /*case '*':
                        result = op1 * op2;
                        printf("%d * %d = %d\n",op1, op2, result);
                        break;

                    case '-':
                        result = op2 - op1;
                        printf("%d - %d = %d\n",op2, op1, result);
                        break;

                    case '/':
                        result = op2 / op1;
                        printf("%d / %d = %d\n",op2, op1, result);
                        break;*/
            }

        }
    } while (c != '\0');

    for (int i = 0; i < op; i++) {
        printf("\t%d: %s\n", i, operands[i]);
    }
//    printf("result: %d\n", operands[0]);
}