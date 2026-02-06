#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main(){
	
	int svrD;
	
	struct sockaddr_in add;
	
	int addlen = sizeof(add);
	char rxBuf[BUF_SIZE] = {0};
	char *txBuf = "Hello from Server \n";
	
	svrD = socket(AF_INET, SOCK_STREAM, 0);
	
	add.sin_family = AF_INET;
	add.sin_addr.s_addr = INADDR_ANY; 		// Default Server Add(0.0.0.0)
	add.sin_port = htons(PORT);
	
	bind(svrD, (struct sockaddr*)&add, sizeof(add));
	listen(svrD, 3);
	
	socklen_t clientLen = sizeof(add);
	int clientD = accept(svrD, (struct sockaddr*) &add, &clientLen);
	
	read(clientD, rxBuf, BUF_SIZE);
	printf("Server: \n");
	printf("msg Rx from Client: %s \n", rxBuf);
	
	printf("msg Tx ro Client  : %s \n", txBuf);
	send(clientD, txBuf, strlen(txBuf), 0);
	
	close(clientD);
	close(svrD);
		
	return 0;
}
