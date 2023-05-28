// A simple, recursive, non-memoized fibonacci implementation.
// Abiram Nadarajah, October 2021
#include <stdio.h>

int fib(int n) {
    if (n < 2) {
    	return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);

    printf("Fibonacci of %d is %d\n", n, fib(n));
    return 0;
}
