#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s <time>\n", argv[0]);
        return 1;
    }

    char *endptr;
    long sec = strtol(argv[1], &endptr, 0);

    if (*endptr != '\0' || sec < 0) {
        printf("invalid value\n");
        return 1;
    }
    
    for (long i = sec; i >= 0; i--) {
        printf("%d\n", i);
        if (i != 0)
            sleep(1);
    }

    return 0;
}
