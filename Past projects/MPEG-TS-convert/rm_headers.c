#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define filename "123"
#define newfile "newfile"

int main(void){

	off_t file_size;		//total file size in bytes
	char *buffer;			//buffer for reading the file
	struct stat stbuf;		//stat for file
	int fd;					//input file
	int fd2;				//output file
	int header_num=0;		//headers num
	int pes_size=188;		//PES size
	
	//0x47 sync byte (start of headers)
	unsigned char headers[]={0x47, 0x40}; 
	
	
	fd = open(filename,O_RDWR);
	fd2 = open(newfile,O_RDWR | O_APPEND | O_CREAT | O_TRUNC);
	
	if (fd == -1 || fd2==-1) {
		printf("The file was not oppened correctly!");
		exit(-1);
	}
	
	
	fstat(fd, &stbuf);
	file_size = stbuf.st_size;
	//printf("Filesize: [%d]\n",file_size);
	
	
	buffer = (char*)malloc(file_size);
	if (buffer == NULL) {
		printf("Error in allocating memory\n");
		exit(-1);
	}
	read(fd, buffer, file_size);			
	
	int i=0;
	
	
	while(i<file_size){
		
		if(buffer[i]==headers[0]){
			printf("<0x%x>\n",buffer[i]);
			printf("<0x%x>\n",buffer[i+1]);
			printf("<0x%x>\n",buffer[i+2]);
			printf("<0x%x>\n",buffer[i+3]);
			printf("\n");
			
			header_num++;
		}else{
			printf("Error in sync byte\n");
			exit(1);	
		}
		
		int z=i+pes_size;
		i+=4;
		
		while(i<z){
			//printf("-----------------------------------\n");
			write(fd2,&buffer[i],sizeof(unsigned char));
			i++;
		}
	}
	printf("headers= %d\n",header_num);
	close(fd);
	close(fd2);
	
	return 0;
}
