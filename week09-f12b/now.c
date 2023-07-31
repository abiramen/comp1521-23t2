#include <stdio.h>
#include <spawn.h>
#include <stdlib.h>
#include <sys/wait.h>

#define DATE_PATH "/usr/bin/date"
#define CURL_PATH "/usr/bin/curl"

extern char **environ;

int main(void) {
    // call posix_spawn to print date +%d-%m-%Y
    pid_t date_pid;

    char *date_argv[] = {
        DATE_PATH,
        "+%d-%m-%Y",
        NULL
    };

    posix_spawn(&date_pid,
                DATE_PATH,
                NULL,
                NULL,
                date_argv,
                environ
                );

    if (waitpid(date_pid, NULL, 0) == -1) {
        perror("waitpid");
        return 1;
    }

    pid_t curl_pid;
    
    char *curl_argv[] = {
        CURL_PATH,
        "-q",
        "wttr.in",
        NULL
    };

    posix_spawn(
        &curl_pid,
        CURL_PATH,
        NULL,
        NULL,
        curl_argv,
        environ      
    );

    if (waitpid(curl_pid, NULL, 0) == -1) {
        perror("waitpid");
        return 1;
    }
    

    return 0;
}
