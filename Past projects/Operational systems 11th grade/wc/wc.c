//--------------------------------------------
// NAME: Eduard Kalfov
// CLASS: 11b
// NUMBER: 16
// PROBLEM: #2
// FILE NAME: wc.c (unix file name)
// FILE PURPOSE:
// Реализация на wc.
// ...
//---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int ccount; // Char count
int wcount; // word count
int lcount; // line count
int total_ccount=0;
int total_wcount=0;
int total_lcount=0;
char str[80]; //String where i store all the arguments from command line

void error_handle(char *argv); 
void read_file(char *argv);
void print(char *file, int ccount, int wcount, int lcount);
int getword(FILE *fp);
void print_smart(char *argv);
void print_smart_total(char *argv);


int main(int argc, char *argv[])
{
  
	int i=1;
	int option=0;
  for (i = 1; i < argc; i++){         // In this loop I add all the argments from command line
            strcat(str,argv[i]);   
            if(strchr(argv[i], '-l') || strchr(argv[i], '-w') || strchr(argv[i], '-c') || strchr(argv[i], '-lw') || strchr(argv[i], '-lc') || strchr(argv[i], '-wc') || strchr(argv[i], '-wl') || strchr(argv[i], '-cl') || strchr(argv[i], '-cw') ){
                    option=1;
          }
        }

 
		if(argc==1){ // Check if we have zero arguments from command line.
			while(getword(stdin)); // Get input from stdin
			printf("%d %d %d\n",lcount,wcount,ccount );
		}
    
      
 for (i = 1; i < argc; i++){
       	if(strcmp("-",argv[i])==0){ //Check if we have argument '-'
			   ccount = wcount =lcount =0;
			   while(getword(stdin));  // Get input from stdin
			    total_ccount += ccount;
    	   total_wcount += wcount;
   			total_lcount += lcount;
   			print_smart(argv[i]); // Print to stdout
   			continue;
		} else if(strchr(argv[i],'-')){
      continue;
    }
	read_file(argv[i]); // reading file
   }
   i=1;
   
   if((argc==2 ) && (strcmp("-l",argv[i])==0 || strchr(argv[i],'-w') ||  strchr(argv[i],'-c') ||  strchr(argv[i],'-lw') ||  strchr(argv[i],'-lc') ||  strchr(argv[i],'-wc') ||  strchr(argv[i],'-wl') ||  strchr(argv[i],'-cl') ||  strcmp("-cw",argv[i])==0 )){
      // This is a special case when there is only option arguments
      while(getword(stdin));
      print_smart(argv[i]);
    }

  if(argc > 2 ) {
       print_smart_total(argv); // Print total count
    }
  
  return 0;
}
//--------------------------------------------
// FUNCTION: getword
// Get next word from the input stream. Return 0 on end of file or error condition. Return 1 otherwise
// PARAMETERS:
// FILE *fp is the argument we pass from command line(the name of the file)
//----------------------------------------------
int getword(FILE *fp){
	int c;
    int word = 0;
       
       if (feof(fp))
         return 0;
           
       while ((c = fgetc (fp)) != EOF){ //Read from file
           if (isalpha(c) || isdigit(c)){ //Check if c is alphabetic char or digit
        	wcount++;
               break;
             }
             ccount++;        
           if ((c) == '\n') 
             lcount++;
      }
     // for (; c != EOF; c = fgetc (fp)){
     //       ccount++;        
     //       if ((c) == '\n') 
     //         lcount++;
     //       if (!isalnum(c)) // isalnum is like isalpha +isdigit
     //         break;
     //     }
     return c != EOF;
}
//--------------------------------------------
// FUNCTION: read_file
// This is where file is being read and total words,chars,lines are counted;
// PARAMETERS:
// char *argv is the argument we pass from command line(the name of the file)
//----------------------------------------------
void read_file(char *argv){
	ccount = wcount = lcount = 0;
	FILE *fp;
	fp = fopen(argv,"r+");
	if(!fp){
		error_handle(argv);
		return;
	}
	while (getword(fp));
    fclose (fp);
     int i=0;
     print_smart(argv);
// print(argv, ccount, wcount, lcount);
    total_ccount += ccount;
    total_wcount += wcount;
   	total_lcount += lcount;
}
//--------------------------------------------
// FUNCTION: print_smart
// Smart printing of words,chars and lines depends on options.
// PARAMETERS:
// char *argv is the argument we pass from command line(the name of the file)
//----------------------------------------------
void print_smart(char *argv){
  if (strstr(str,"-l")){
         if (strstr(str,"-lc") || ( strstr(str,"-l")) && (strstr(str,"-c")) ){
           printf ("  %d  %d  %s\n",lcount, ccount, argv);
        } 
	else if (strstr(str,"-lw") || ( strstr(str,"-l")) && (strstr(str,"-w"))  ){
           printf ("  %d  %d  %s\n",lcount, wcount, argv);
        }
	else
           printf ("  %d  %s\n",lcount, argv);
      }
   else if (strstr(str,"-w")){
          if (strstr(str,"-wc") || ( strstr(str,"-w")) && (strstr(str,"-c"))){
           printf ("  %d  %d  %s\n",wcount, ccount, argv);
        }

        else if (strstr(str,"-wl") || ( strstr(str,"-w")) && (strstr(str,"-l"))){
           printf ("  %d  %d  %s\n",wcount, lcount, argv);
        }

          else printf ("  %d  %s\n",wcount, argv);
        }
    else if (strstr(str,"-c")){
          if (strstr(str,"-cl") || ( strstr(str,"-c")) && (strstr(str,"-l"))){
           printf ("  %d  %d  %s\n",ccount, lcount, argv);
        }

        else  if (strstr(str,"-cw") || ( strstr(str,"-c")) && (strstr(str,"-w"))){
           printf ("  %d  %d  %s\n",ccount, wcount, argv);
        }
         else  printf ("  %d  %s\n",ccount, argv);
        }

        else{
            print(argv, ccount, wcount, lcount);
        }
}
//--------------------------------------------
// FUNCTION: print_smart_total
// Smart printing of total words,chars and lines depends on options.
// PARAMETERS:
// char *argv is the argument we pass from command line(the name of the file)
//----------------------------------------------
void print_smart_total(char *argv){
  if (strstr(str,"-l")){
         if (strstr(str,"-lc") || ( strstr(str,"-l")) && (strstr(str,"-c")) ){
           printf ("  %d  %d total\n",total_lcount, total_ccount);
        } 
	else if (strstr(str,"-lw") || ( strstr(str,"-l")) && (strstr(str,"-w"))  ){
           printf ("  %d  %d  total\n",total_lcount, total_wcount);
        } 
	else
           printf ("  %d  total\n",total_lcount);
      }
     else if (strstr(str,"-w")){
          if (strstr(str,"-wc") || ( strstr(str,"-w")) && (strstr(str,"-c"))){
           printf ("  %d  %d  total\n",total_wcount, total_ccount);
        }
	else if (strstr(str,"-wl") || ( strstr(str,"-w")) && (strstr(str,"-l"))){
           printf ("  %d  %d  total\n",total_wcount, total_lcount);
        }
	else printf (" %d  total\n",total_wcount);
        }
     else  if (strstr(str,"-c")){
          if (strstr(str,"-cl") || ( strstr(str,"-c")) && (strstr(str,"-l"))){
           printf ("  %d  %d  total\n",total_ccount, total_lcount);
        }
	else  if (strstr(str,"-cw") || ( strstr(str,"-c")) && (strstr(str,"-w"))){
           printf ("  %d  %d  total\n",total_ccount, total_wcount);
        }
        else  printf (" %d  total\n",total_ccount);
        }
	else{
           print("total", total_ccount, total_wcount, total_lcount);
        }
}
void print(char *file, int ccount, int wcount, int lcount)
     {
       printf ("%d %d %d %s\n", lcount, wcount, ccount, file);
     }
//--------------------------------------------
// FUNCTION: error_handle
// Function to handle the errors when we try to open a file.
// PARAMETERS:
// char* argv - argv is the argument we pass from command line(the name of the file)
//----------------------------------------------
void error_handle(char *argv){
	if(errno==ENOENT){
		fprintf(stderr,"wc: %s: No such file or directory\n",argv); // Output to standart error stream
	}
	if(errno==EPERM || errno==EACCES){
		fprintf(stderr,"wc: %s: Permission denied\n",argv);	// Output to standart error stream
	}
}
