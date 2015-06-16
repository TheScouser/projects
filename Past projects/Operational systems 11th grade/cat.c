//--------------------------------------------
// NAME: Eduard Kalfov
// CLASS: 11b
// NUMBER: 16
// PROBLEM: #1
// FILE NAME: cat.c (unix file name)
// FILE PURPOSE:
// Реализация на cat. Програмата трябва да извежда съдържание на стандартния изход и да чете от стандартния вход.
// ...
//---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


#define SIZE 500 // Size of buffer

void fileRead(char *argv); 
void error_handle(char *argv);

int main(int argc, char *argv[])
{	
	int i;
	if(argc==1){ // Check if we have zero arguments from command line.
		char c;
			while( (c = getchar()) != EOF ) { // Take the input from standart input(until end of file) and print it to standart output.
				printf("%c", c);
			}
			
	}

	for (i = 1; i < argc; i++){
		if(strchr(argv[i], '-')){ //Check if we have argument '-'
			char c;
			while( (c = getchar()) != EOF ) {
				printf("%c", c);		// Take the input from standart input(until end of file) and print it to standart output.
			}
			continue;
		}
		
		file_read(argv[i]);
	}

	return 0;
}

//--------------------------------------------
// FUNCTION: file_read
// The function reads file and prints it to standart output.
// PARAMETERS:
// char* argv - argv is the argument we pass from command line(the name of the file)
//----------------------------------------------

void file_read(char *argv){
	char buffer[SIZE]; //buffer where we store the information we read from the file
	int fd = open(argv,O_RDONLY); // file descriptor
	if ( fd != -1)
	{
		ssize_t bytes_read; 
		do{
			bytes_read = read(fd, buffer, sizeof(buffer) - 1); // Read the next line's worth of bytes.
			buffer[bytes_read] = '\0'; //Set terminating sybmol
			printf("%s", buffer);	// Print buffer to standart input
		}while(bytes_read != 0);
	}
	else{
		error_handle(argv);
	}
	close(fd);
}


//--------------------------------------------
// FUNCTION: error_handle
// Function to handle the errors when we try to open a file.
// PARAMETERS:
// char* argv - argv is the argument we pass from command line(the name of the file)
//----------------------------------------------

void error_handle(char *argv){
	if(errno==ENOENT){
		fprintf(stderr,"cat: %s: No such file or directory\n",argv); // Output to standart error stream
	}
	if(errno==EPERM || errno==EACCES){
		fprintf(stderr,"cat: %s: Permission denied\n",argv);	// Output to standart error stream
	}
}
