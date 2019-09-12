#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char ** argv[]) {
    int n;
    sscanf((const char *) argv[1], "%d", &n);
    pid_t pid;

    if ((pid = fork()) == 0)
        printf("Hello from child [%d - %d]\n", pid, n);
    else printf("Hello from parent [%d - %d]\n", pid, n);

    return 0;
}
