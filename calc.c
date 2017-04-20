#include "add.h"
#include "mult.h"
#include "alloc.h"

char *calc(char *input) {
    char *operands[20];
    char *operand, *op1, *op2;

    char op = 0, ocp = 0, op_len = 0;

    char c;
    int i = 0;

    do {
        c = input[i++];
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
            c = input[i++];
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
                    add(op2, op1);
                    op++;
                    break;
                case '*':
                    operands[op++] = mult(op2, op1);
                    break;
            }

        }
    } while (c != '\0');

    return operands[0];
}