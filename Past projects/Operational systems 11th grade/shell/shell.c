//--------------------------------------------
// NAME: Eduard Kalfov
// CLASS: 11b
// NUMBER: 16
// PROBLEM: #4
// FILE NAME: shell.c (unix file name)
// FILE PURPOSE:
// Команден интерпретатор.
// ...
//---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/param.h>

void error_handle(char *argv);
char** parse_cmdline( char *cmdline);

int main(int argc, char *argv[])
{
	int i,status;
	char cmdline[100];
	char** str;

	// for (i = 1; i < argc; i++)
	// {
	// 	printf("%s\n",argv[i]);
	// 	str[i-1]=argv[i];
	// }

	pid_t pid;
	pid = fork();
	if (pid < 0){
		status = -1;
		printf("Unsuccessful fork\n");
	}
	else if(pid == 0){
		execv(argv[1],NULL,NULL);
	}
	else{
		if(waitpid(pid,&status,0) != pid){
			status = -1;
			printf("FAIL!\n");
		}
		printf("Child process finished...\n");
	}

	return status;
}


char** parse_cmdline(char *cmdline){
	char** str;
	char* pch;
	int i=0;

	pch = strtok(cmdline, " ");

	while(pch != NULL){
		//	printf("%s\n", pch);
		pch = strtok(NULL," ");
		str[i]=pch;
	}

	return str;
}



//--------------------------------------------
// FUNCTION: error_handle
// Function to handle the errors when we try to open a file.
// PARAMETERS:
// char* argv - argv is the argument we pass from command line(the name of the file)
//----------------------------------------------
void error_handle(char *argv){
	if(errno==ENOENT){
		fprintf(stderr,"./%s: No such file or directory\n",argv); // Output to standart error stream
	}
	if(errno==EPERM || errno==EACCES){
		fprintf(stderr,"./%s: Permission denied\n",argv);	// Output to standart error stream
	}
}