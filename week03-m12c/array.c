#include <stdio.h>

int array[] = {1, 5, 2, 1};

char hello[] = {'h', 'e', 'l', 'l', 'o'};

int main(void) {
    for (int i = 0; i < 4; i++) {
        printf("array[%d] = %d\n", i, array[i]);
        printf("&array[%d] = %p\n", i, &array[i]);
        printf("array = %p\n", array);

        // &array[0] = array
        // &array[1] = &array[0] + 4  = &array[0] + 4 * 1
        // &array[2] = &array[0] + 8  = &array[0] + 4 * 2
        // &array[3] = &array[0] + 12 = &array[0] + 4 * 3
        // &array[i] =                  &array[0] + 4 * i

        // &array[i] =                  &array[0] + sizeof(element) * i
    }
    
}
