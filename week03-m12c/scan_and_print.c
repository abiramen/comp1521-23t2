#include <stdio.h>

#define ARRAY_SIZE 10

int numbers[ARRAY_SIZE] = {0};

int main(void) {
    int i;

read_loop__init:
    i = 0;
read_loop__cond:
    if (i >= ARRAY_SIZE) goto read_loop__end;
read_loop__body:
    scanf("%d", &numbers[i]);           // &numbers[i] = numbers + 4 * i
read_loop__step:
    i++;
    goto read_loop__cond;

read_loop__end:

print_loop__init:
    i = 0;
print_loop__cond:
    if (i >= ARRAY_SIZE) goto print_loop__body;
print_loop__body:
    printf("%d", numbers[i]);           // &numbers[i] = numbers + 4 * i
    putchar(' ');
print_loop__step:
    i++;
    goto print_loop__cond;
print_loop__end:
    return 0;
}
