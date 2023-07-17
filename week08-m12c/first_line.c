// Write a C program, first_line.c, which is given one command-line argument -
// the name of a file - and which prints the first line of that file to stdout.
// If given an incorrect number of arguments, or if there was an error opening
// the file, it should print a suitable error message.
//
// A line may be of any size.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *stream = fopen(argv[1], "r");

    if (stream == NULL) {
        perror(argv[1]);
        return 1;
    }

    int c;

    while ((c = fgetc(stream)) != EOF && c != '\n') {
        putchar(c);         // fputc(c, stdout);
    }
   
    putchar('\n');

    return 0;
}
