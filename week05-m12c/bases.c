#include <stdio.h>

int main(void) {

    int n = 0x6b ^ 0xaa;
    printf("Decimal: %d\n", n);
    printf("Hexadecimal: %x or %X\n", n, n);
    printf("Octal: %o\n", n);

    return 0;
}
