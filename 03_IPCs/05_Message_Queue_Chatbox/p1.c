#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define max 50

struct msgBuff{
	long msgT;
	char msgD[max];
};

int main(){
	
	key_t key;
	int msgID;

	key = ftok("progfile", 65);
	msgID = msgget(key, 0666 | IPC_CREAT);

	struct msgBuff msg;
	// int choice;
	// printf("Enter 1 to send msg: \n");
	while(1){
		// printf("Enter: ");
		// scanf("%d", &choice);
		// getchar();
		
		// if(choice == 1){
		// 	choice = 0;
		// }

		printf("A: ");
		fgets(msg.msgD, max, stdin);
		msg.msgT = 1;
		msgsnd(msgID, &msg, sizeof(msg.msgD), 0);

		msgrcv(msgID, &msg, sizeof(msg.msgD), 2, 0);
		printf("B: %s \n", msg.msgD);
	}

	printf("Message Sent... \n");
	return 0;
}
