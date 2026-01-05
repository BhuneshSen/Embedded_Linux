#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *shmaddr;

    // Generate unique key
    key = ftok("shmfile", 65);

    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    // Attach shared memory to process
    shmaddr = (char *) shmat(shmid, NULL, 0);

    // Write data to shared memory
    strcpy(shmaddr, "Hello from Shared Memory Writer");

    printf("Writer: Data written to shared memory\n");

    // Detach shared memory
    shmdt(shmaddr);

    return 0;
}
