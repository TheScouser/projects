#include <stdio.h>
#include <string.h>

	
int main(){
	char bigstr[80],str[80];
	int i;
	
	
	for(; ;)
	{	

		
		printf("Vuvedete niz: ");
		gets(str);
		if(!strcmp(str,"quit")) break;			
		if(strlen(bigstr)+strlen(str) < 80){
			strcat(bigstr,str);
			strcat(bigstr,"\n");		
		
		}


	}
	printf("%s",bigstr);

	return 0; 
}
	
