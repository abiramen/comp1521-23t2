#include <stdio.h>

char array[] = {'h', 'e', 'l', 'l', 'o'};

int main(void) {

    printf("%p %p\n", array, &array[0]);
    return 0;
}
