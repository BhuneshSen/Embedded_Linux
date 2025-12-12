#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	
	const char* namedPipe = "/tmp/namedPipe";
	char buff[50];
	
	mkfifo(namedPipe, 0666);
	
	int fd = open(namedPipe, O_RDONLY);
	
	read(fd, buff, sizeof(buff));
	
	printf("Data Received: %s \n", buff);
	
	close(fd);
	
	return 0;
}
