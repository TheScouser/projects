#include <stdio.h>
#include <stdlib.h>

int main(){
 char* nameOfFile;
        nameOfFile = (char*)malloc(sizeof(char)*100);        
        printf("Enter  the name of file:\n");
        scanf("%s", nameOfFile);
        FILE* fp;
        fp = fopen(nameOfFile, "r");
        if(fp != NULL) {        
                char c;
                while((c = fgetc(fp)) != EOF) {
                        printf("%c",c);
                }
                fclose(fp);
        }
        else {
                printf("File do not exist or permission denied.\n");
        }
        free(nameOfFile);
        return 0;
	}
