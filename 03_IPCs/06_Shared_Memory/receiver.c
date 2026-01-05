#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *shmaddr;

    // Generate same key
    key = ftok("shmfile", 65);

    // Access shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    // Attach shared memory
    shmaddr = (char *) shmat(shmid, NULL, 0);

    // Read data
    printf("Reader: Data read = %s\n", shmaddr);

    // Detach shared memory
    shmdt(shmaddr);

    // Destroy shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
