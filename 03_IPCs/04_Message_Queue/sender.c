#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX 100

struct msgbuf {
    long mtype;
    char mtext[MAX];
};

int main() {
    key_t key;
    int msgid;
    struct msgbuf msg;
    
    // Generate unique key
    key = ftok("msgfile", 65);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    msg.mtype = 1;   // message type
    strcpy(msg.mtext, "Hello from Writer");

    // Send message
    msgsnd(msgid, &msg, sizeof(msg.mtext), 0);

    printf("Writer: Message sent\n");

    return 0;
}
