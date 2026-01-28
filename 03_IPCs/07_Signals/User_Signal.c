#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* Signal handler function */
void signal_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        printf("Child: SIGUSR1 received from parent!\n");
    }
}

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }

    /* Child process */
    if (pid == 0)
    {
        /* Register signal handler */
        signal(SIGUSR1, signal_handler);

        printf("Child: Waiting for signal...\n");

        while (1)
        {
            pause();   // Wait for signal
        }
    }
    /* Parent process */
    else
    {
        sleep(2);  // Give time to child
        printf("Parent: Sending SIGUSR1 to child\n");
        kill(pid, SIGUSR1);
    }

    return 0;
}