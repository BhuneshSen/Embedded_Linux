// Sender – sends a message into the queue.

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgqueue.h"

int main() {
    struct msg_buffer message;
    key_t key = MSG_KEY;

    // Create message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);

    message.msg_type = 1;
    sprintf(message.msg_text, "Hello from sender!");

    // Send message
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);

    printf("Message sent: %s\n", message.msg_text);
    return 0;
}
