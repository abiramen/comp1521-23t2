#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);

    printf("Decimal: %d\n", n);
    printf("Hexadecimal: %x or %X\n", n, n);
    printf("Octal: %o\n", n);

    return 0;
}
