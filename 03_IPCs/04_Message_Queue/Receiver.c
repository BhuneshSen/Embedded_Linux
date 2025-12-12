// Receiver – reads the message from the queue.

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgqueue.h"

int main() {
    struct msg_buffer message;
    key_t key = MSG_KEY;

    // Access message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Receive message
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);

    printf("Message received: %s\n", message.msg_text);

    // Destroy queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
