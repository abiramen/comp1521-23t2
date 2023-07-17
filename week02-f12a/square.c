#include <stdio.h>

int main(void) {
    int x;
    int y;
    printf("Enter a number: ");
    scanf("%d", &x);
    y = x * x;
    printf("%d", y);
    putchar('\n');
    return 0;
}
