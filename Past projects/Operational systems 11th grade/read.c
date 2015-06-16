#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

 int main()
{
int fd;
ssize_t bytes_read;
unsigned char buffer[100];

fd = open("/tmp/file.txt", O_WRONLY );

while(bytes_read !=0){
	bytes_read = read(fd,buffer,100);
	 
}
	printf("%s\n",buffer );


	return 0;
}


