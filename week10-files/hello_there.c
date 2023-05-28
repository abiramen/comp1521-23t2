#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    char *string = data;
    while (1) {
        printf("%s\n", string);
    }
    return NULL;
}

int main(void) {
    // TODO: create a thread
    
    // TODO: print the main message

    return 0;
}
