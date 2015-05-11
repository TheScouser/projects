#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char* argv[]){

	off_t file_size;		//total file size in bytes
	char *buffer;			//buffer for reading the file
	struct stat stbuf;		//stat for file
	int fd;					//input file
	int header_num=0;		//headers num
	int pes_size=188;		//PES size
	int z;					//inner counter
	int i;					//bytes read
	int range;				//range outside the buffer
	unsigned char pid;
	unsigned char pat = 0xFF;
	//0x47 sync byte (start of headers)
	unsigned char headers[]={0x47}; 
	
	
	fd = open(argv[1],O_RDWR);
	
	if (fd == -1) {
		printf("The file was not oppened correctly!\n");
		exit(-1);
	}
	
	
	fstat(fd, &stbuf);
	file_size = stbuf.st_size;
	
	
	
	buffer = (char*)malloc(sizeof(unsigned char)*4096);
	if (buffer == NULL) {
		printf("Error in allocating memory\n");
		exit(-1);
	}
	
	i=read(fd, buffer, sizeof(unsigned char)*4096);			
	z=0;
	while(i!=0){
		
		range=0;
		
		while(z<i){
			
			if((z+188)>4096){			//if the next header is in the next buffer
				range=(z+188)-4096;
				//printf("\n=%d=\n\n",header_num);
				break;
			}
			
			if(buffer[z]==headers[0] ){
				header_num++;
				printf("-[%d]-\n",header_num);
				printf("<0x%x>\n",buffer[z]);
				printf("<0x%x>\n",buffer[z+1]);
				printf("<0x%x>\n",buffer[z+2]);
				printf("<0x%x>\n",buffer[z+3]);
				printf("\n");
					
			if(buffer[z+1] | pat){
				pid = ((buffer[z+1] & 0x1f) << 8) | buffer[z+2];
				if(pid != 0)
					printf("THIS IS PID: %x\n", pid);				
				}
				
			}else{
				printf("Error in sync byte\n");
				exit(1);	
			}
			
			
			z+=188;
		}
		
		int index=0;		//index from wich to copy
		int offset=0;		//if there needs to be offset in the buffer
		
		if(range!=0){
			index=188-range;
			index=4096-index;
			
			//printf("[%x]",buffer[index]);
			int index_start=0;
			for(;index<4096;index++){
				buffer[index_start]=buffer[index];
				index_start++;
			}
			offset=index_start;

		}
		
		
			//printf("[#(%x)#]\n",buffer[0]);
			//printf("[#(%x)#]\n",buffer[1]);
			//printf("[#(%x)#]\n",buffer[2]);
			//printf("[#(%x)#]\n",buffer[3]);
			
		
		i=read(fd, buffer+offset, (sizeof(unsigned char)*(4096-(offset*2))));
			printf("[i = %d]\n",i);
			//printf("^^^[#(%x)#]\n",buffer[188+0]);
			//printf("^^^[#(%x)#]\n",buffer[188+1]);
			//printf("^^^[#(%x)#]\n",buffer[188+2]);
			//printf("^^^[#(%x)#]\n",buffer[188+3]);
	
		
		z=0;
		
	}
	
	printf("headers= %d\n",header_num);
	close(fd);
	
	return 0;
}
