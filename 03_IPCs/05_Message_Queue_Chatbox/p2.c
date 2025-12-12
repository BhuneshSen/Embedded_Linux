#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgBuff{
	long msgType;
	char msgTxt[50];
};

int main(){
	
	key_t key;
	int msgID;

	key = ftok("progfile", 65);
	msgID = msgget(key, 0666 | IPC_CREAT);
	printf("msgID: %d \n", msgID);
	struct msgBuff msg;
	
	int choice;
	printf("Enter 1 to send msg: \n");

	while(1){
		msgrcv(msgID, &msg, sizeof(msg.msgTxt), 1, 0);
		printf("A: %s \n", msg.msgTxt);

		printf("B: ");
		fgets(msg.msgTxt, sizeof(msg.msgTxt), stdin);
		msg.msgType = 2;
		msgsnd(msgID, &msg, sizeof(msg.msgTxt), 0);

		// printf("Enter: ");
		// scanf("%d", &choice);
		// getchar();
		// if(choice == 1){
		// 	choice = 0;
		// }
	}
	return 0;
}
