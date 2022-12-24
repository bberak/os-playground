#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Hello world (pid: %d) \n", (int) getpid());

    int forkResult = fork();

    if (forkResult < 0) { // The fork system call failed
        fprintf(stderr, "fork failed \n");
        exit(1);
    } else if (forkResult == 0) { // The child process (forked) takes this path
        printf("I am the child process (pid: %d) \n", (int) getpid());
    } else { // The parent process takes this path
        wait(NULL); // Wait for child to complete
        printf("I am the parent process of %d (pid: %d) \n", forkResult, (int) getpid());
    }

    return 0;
}