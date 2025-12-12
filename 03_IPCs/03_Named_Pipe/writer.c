#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
	
	const char *namedPipe = "/tmp/namedPipe";
	
	// Create namepipe(FIFO) - it's a file
	mkfifo(namedPipe, 0666);					// 0666 - read and write permission for everyone
	
	int fd = open(namedPipe, O_WRONLY);
	
	char msg[] = "Hello from Writer";
	write(fd, msg, sizeof(msg));
	close(fd);
	
	return 0;
}


/*
// Steps to send data via namedPipe

create string with file Name
open file in write mode
write data
close file
*/
