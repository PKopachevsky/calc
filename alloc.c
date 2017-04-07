#include <stdio.h>

#define BUF_SIZE 10000

static char allocbuf[BUF_SIZE];
static char *allocp = allocbuf;

char *alloc(int n){
    if (allocbuf + BUF_SIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}