#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("child: pid = %d; id = %d\n", pid, getpid());
    } else {
        printf("parent: pid = %d; id = %d\n", pid, getpid());
    }
    return 0;
}
