// non recursively calculate a factorial in C
// Abiram Nadarajah, Feb 2022

#include <stdio.h>

int main(void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
loop_i_to_n__init:
    int i = 1;
loop_i_to_n__cond:
    if (i > n) goto loop_i_to_n__end;
loop_i_to_n__body:
    fac *= i;
loop_i_to_n__step:
    i++;
    goto loop_i_to_n__cond;

loop_i_to_n__end:

    printf("n! = ");
    printf("%d", fac);
    putchar('\n');
    return 0;
}
