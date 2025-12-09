#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	
	printf("q1.c Initiated...\n");
	
	int fd[2];									// file descriptor 
	char buffer[30];
	if(pipe(fd) == -1){
		printf("Pipe Failed... \n");
	}
	pid_t pid = fork();
	
	if(pid < 0){
		perror("fork failed..\n");
	}

	if( pid != 0){
		printf("Parent Process \n");
		close(fd[0]);
		char msg[] = "(P2C)Hello EmbeddedOS_";	// Parent to Child
		write(fd[1], msg, strlen(msg)+1);		// sending data to adjusent process
		close(fd[1]);
		
	}
	else{
		printf("Child Process \n");
		close(fd[1]);							// close Read write end
		read(fd[0], buffer, sizeof(buffer));	// reading data send by adjusent parent process
		close(fd[0]);
		
	}
	
	// echo msg receive by child process
	if(pid == 0){
		printf("Msg Received: %s \n", buffer);
	}
	printf("End of Process %d \n", getpid());
	return 0;
}


/*
int fd[2] - fd is file descriptor

fd[0] - read end;
fd[1] - write end;

pipe(fd) - function get arr of 2 int (as mention above), return -1 if fail to set-up communication


*/
