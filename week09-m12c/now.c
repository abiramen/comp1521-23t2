#include <stdio.h>
#include <spawn.h>
#include <sys/wait.h>

#define DATE_PATH "/usr/bin/date"

extern char **environ;

int main(void) {


    char *spawn_argv[] = {
        DATE_PATH,
        "+%d-%m-%Y",
        NULL
    };

    pid_t spawn_date_pid;
    posix_spawn(&spawn_date_pid,                    // pointer to an uninitialised pid_t
                DATE_PATH,                          // path to the program for the new process to execute
                NULL,                               // file actions - generally NUL
                NULL,                               // spawn attributes
                spawn_argv,                         // argv for the new process
                environ
                );

    if (waitpid(spawn_date_pid, NULL, 0) == -1) {
        perror("waitpid");
    }

    pid_t spawn_time_pid;

    char *spawn_time_argv[] = {
        DATE_PATH,
        "+%T",
        NULL

    };

    posix_spawn(&spawn_time_pid,                    // pointer to an uninitialised pid_t
                DATE_PATH,                          // path to the program for the new process to execute
                NULL,                               // file actions - generally NUL
                NULL,                               // spawn attributes
                spawn_time_argv,                    // argv for the new process
                environ
                );


    if (waitpid(spawn_time_pid, NULL, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    // // call posix_spawn to print date +%T

    return 0;
}
