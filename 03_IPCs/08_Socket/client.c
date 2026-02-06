#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(){
	int clientD = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in add;
	add.sin_family = AF_INET;
	add.sin_port = htons(PORT);
	inet_pton(AF_INET, "127.0.0.1", &add.sin_addr);
	
	connect(clientD, (struct sockaddr*)&add, sizeof(add));
	
	printf("Client: \n");
	char *txBuf = "Hello from Client";
	send(clientD, txBuf , strlen(txBuf), 0);
	printf("msg Tx to Server: %s \n", txBuf);
	
	char rxBuf[BUF_SIZE] = {0};
	read(clientD, rxBuf, BUF_SIZE);
	printf("msg Rx from Server: %s \n", rxBuf);
	
	return 0;
}
