#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
using namespace std;
 int main(int argc, char *argv[])
{
	int fd;
size_t bytes_read;
unsigned char buffer[100];
fd = open("/tmp/file.txt", O_RDONLY );
if (fd != -1)
{
	bytes_read = read(fd,buffer,100);
	cout << bytes_read << endl;
}



	return 0;
}



