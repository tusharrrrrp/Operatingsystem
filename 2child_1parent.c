#include <stdio.h>      // For printf() and perror()
#include <unistd.h>     // For fork(), getpid(), getppid()
#include <sys/wait.h>   // For wait()
#include <stdlib.h>     // For exit()

int main() {
    pid_t pid1, pid2;

    // First fork to create the first child
    pid1 = fork();

    if (pid1 == -1) {
        // If fork() returns -1, an error happened
        perror("First fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid1 == 0) {
        // Code executed by first child
        printf("First child process: PID=%d, Parent PID=%d\n", getpid(), getppid());
        exit(EXIT_SUCCESS); // Exit first child successfully
    }
    else {
        // Code executed by parent
        // Second fork to create the second child
        pid2 = fork();

        if (pid2 == -1) {
            perror("Second fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid2 == 0) {
            // Code executed by second child
            printf("Second child process: PID=%d, Parent PID=%d\n", getpid(), getppid());
            exit(EXIT_SUCCESS); // Exit second child successfully
        }
    }

    // Only the parent executes this code
    // Parent waits for both children to exit
    wait(NULL); // Wait for first child to exit
    wait(NULL); // Wait for second child to exit
    printf("Parent process: PID=%d\n", getpid());

    return EXIT_SUCCESS;
}
