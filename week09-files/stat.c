#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        struct stat s;

        if (stat(argv[i], &s) != 0) {
            perror("stat");
            // exit(1);
            return 1;
        }


        printf("-- file: %s --\n", argv[i]);


        printf("st_ino = %ld\n", s.st_ino);
        printf("st_mode = %o\n", s.st_mode);

        // TODO: How can we check what kind of filesystem object this is?

        printf("st_uid = %d\n", s.st_uid);
        printf("st_gid = %d\n", s.st_gid);
        printf("st_size = %ld\n", s.st_size);
        printf("st_blksize = %ld\n", s.st_blksize);
        printf("st_blocks = %ld\n", s.st_blocks);
        printf("st_atime = %ld\n", s.st_atime);
        printf("st_mtime = %ld\n", s.st_mtime);
        printf("st_ctime = %ld\n", s.st_ctime);
        putchar('\n');
    }
}
