#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100
struct msgbuf {
    long mtype;
    char mtext[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct msgbuf msg;

    key = ftok("msgfile", 65);           // Generate same key


    msgid = msgget(key, 0666 | IPC_CREAT);    // Access message queue

    msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0);    // Receive message of type 1

    printf("Reader: Message received = %s\n", msg.mtext);

    // Destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
