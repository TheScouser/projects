//--------------------------------------------
// NAME: Eduard Kalfov
// CLASS: 11b
// NUMBER: 16
// PROBLEM: #3
// FILE NAME: ls.c (unix file name)
// FILE PURPOSE:
// Реализация на ls.
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
int main (int argc, char *argv[]) {
    int len,i=0,dir,q,j,block=0;
   struct stat sts;
    struct dirent *pDirent;
    struct dirent **d;
    DIR *pDir;
    char buffer[100];
    int option=0;
	
    if (argc < 2) {                               //When no argument is passed the output is the files or directories in the current directory.
    	pDir = opendir (".");
        while ((pDirent = readdir(pDir)) != NULL){ //Reading all entries in the directory
        	if(pDirent->d_name[0] == '.'){ //Excluding hidden files
    	 		continue;
    	 	}
        	printf ("%s\n", pDirent->d_name);//Printing the names of the files.
        }
        return 1;
    }
    else{
    	if(argc==2 && strcmp("-l",argv[1])==0){//When only -l is passed it works like the previous "if" but additional info is shown.
    		pDir = opendir (".");
        while ((pDirent = readdir(pDir)) != NULL){
        	if(pDirent->d_name[0] == '.'){
    	 		continue;
    	 	}
    	 	print_long(pDirent->d_name); // Function that prints the additional info
        	printf ("%s\n", pDirent->d_name);
    	}
    	}

	}
for (i = 1; i < argc; ++i)          //This loop checks the arguments for -l 
   {
   		if(strcmp("-l",argv[i])==0){
   			option=1;                //If -l is passed then option becomes 1
   		}
   }
    for(i = 1; i < argc;i++){
    	  if(option==1){
    	  	if(strcmp("-l",argv[i])==0){ //Check for -l again so we can exclude it from arguments list
    	 		continue;
    	  	}
    	  }
		pDir = opendir (argv[i]);//Function which opens directory
    	if (pDir == NULL) {
    	 	error_handle(argv[i]);
    		if(errno != ENOTDIR){
    	 		stat(argv[i], &sts);
    	 		continue;
    	 	}
    		if(option==1){
    			printf("\n%s:\n", argv[i]); 
				print_long(argv[i]);    
				printf("%s\n",argv[i]);
    	 		continue;
    	 	}
    	 	else{
    	 		printf("%s\n",argv[i]);
    	 		continue;
    	 	}
    	}
        printf("\n%s:\n", argv[i]);
    	while ((pDirent = readdir(pDir)) != NULL) {//Reading all entries in the directory
			if(pDirent->d_name[0] == '.'){ //Excluding hidden entries
    	 		continue;
    	 	}
    	 	stat(pDirent->d_name, &sts); //Getting information about file.
    	 	if(option==1){

    	 		strcpy(buffer,argv[i]);
    	 		strcat(buffer,"/");
    	 		strcat(buffer,pDirent->d_name);    //Buffer is used to get the exact path of the files and directories so they can be properly used in stat.
				print_long(buffer);
				int s = stat(buffer,&sts);
                if(S_ISDIR(sts.st_mode)){
                    printf("\e[1;34m%-6s\e[m \n", pDirent->d_name);   // This prints the name in blue if the it's directory.
                }
                 else{
                    printf ("%s\n",pDirent->d_name);
			     }
			}
                else{
         		        if(S_ISDIR(sts.st_mode)){
                    printf("\e[1;34m%-6s\e[m \n", pDirent->d_name);   
                }
                 else{
                    printf ("%s\n",pDirent->d_name);
         	}
    	}
	}
}
    closedir (pDir);// Closing the opened directory
return 0;
}

//--------------------------------------------
// FUNCTION: print_long
// Function which prints additional info when -l is passed.
// PARAMETERS:
// char* argv - argv is the argument we pass from command line(the name of the file)
//----------------------------------------------

int print_long(char *argv){
	char *p=getenv("USER");
    char name[MAXHOSTNAMELEN];
  	size_t namelen = MAXHOSTNAMELEN;
	struct stat sts;
	struct group  *gr = getgrgid(sts.st_gid);
	if(stat(argv,&sts) < 0)    
		return 1;
	printf(S_ISDIR(sts.st_mode) ? "d" : "-" );
	printf(sts.st_mode & S_IWUSR ? "w" : "-" );
	printf(sts.st_mode & S_IXUSR ? "x" : "-" );
	printf(sts.st_mode & S_IRGRP ? "r" : "-" );
	printf(sts.st_mode & S_IWGRP ? "w" : "-" );
	printf(sts.st_mode & S_IXGRP ? "x" : "-" );
	printf(sts.st_mode & S_IROTH ? "r" : "-" );
	printf(sts.st_mode & S_IWOTH ? "w" : "-" );
	printf(sts.st_mode & S_IXOTH ? "x" : "-" );
	printf(" %-2d ",(int) sts.st_nlink);
	printf("%-8s ",p); //Prints the username
	if (gethostname(name, namelen) != -1) //Getting computer name
    printf("%-10s ", name);
	printf("%9lld ", (long long) sts.st_size);
	char *time = ctime(&sts.st_mtime);
	time[strlen(time)-1]='\0';
	printf("%s ",time );
}

//--------------------------------------------
// FUNCTION: error_handle
// Function to handle the errors when we try to open a file.
// PARAMETERS:
// char* argv - argv is the argument we pass from command line(the name of the file)
//----------------------------------------------
void error_handle(char *argv){
	if(errno==ENOENT){
		fprintf(stderr,"ls: Cannot access %s: No such file or directory  \n",argv); // Output to standart error stream
	}
	if(errno==EPERM || errno==EACCES){
		fprintf(stderr,"ls: Cannot open directory %s: Permission denied  \n",argv);	// Output to standart error stream
	}
}
