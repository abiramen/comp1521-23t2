#include <stdio.h>

int main(void) {

    int n = 0x4d ^ 0xaa;
    printf("Decimal: %d\n", n);
    printf("Hexadecimal: %x and %X\n", n, n);
    printf("Octal: %o\n", n);
    return 0;
}
