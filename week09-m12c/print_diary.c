/**
 * Write a C program, print_diary.c,
 * which prints the contents of the file $HOME/.diary to stdout.
 * 
 * Be sure to handle any errors!
 * snprintf is a convenient function for constructing the pathname of the diary file.
 * (it's also pretty handy for subset3 of a certain assignment.)
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIARY_PATH "/.diary"


int main(void) {

    char *home_dir = getenv("HOME");

    int concatenated_size = strlen(home_dir) + strlen(DIARY_PATH) + 1;

    char *concatenated_paths = malloc(concatenated_size * sizeof(char));


    if (home_dir == NULL) {
        fprintf(stderr, "$HOME is not set\n");
        return 1;
    }

    snprintf(concatenated_paths, concatenated_size, "%s%s", home_dir, DIARY_PATH);
    // printf("home directory is %s\n", home_dir);

    // TODO: construct full_path in order to open the file 
    FILE *stream = fopen(concatenated_paths, "r");
    if (stream == NULL) {
        perror(concatenated_paths);
        exit(1);
    }

    int c;
    while ((c = fgetc(stream)) != EOF) {
        putchar(c);
    }

    fclose(stream);
    return 0;
}
