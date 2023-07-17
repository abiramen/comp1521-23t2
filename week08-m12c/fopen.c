#include <stdio.h>
#include <errno.h>


int main(void) {
    FILE *stream = fopen("hello.txt", "r");
    if (stream == NULL) {
        perror("hello.txt");
        return 1;
    }

    fclose(stream);
    return 0;
}
