 //Edward Kalfov 10v nomer 13
 #include <stdio.h>
 #include <stdlib.h>
 int main(int argc, char *argv[]){
	 FILE *from,*to;
	 char c;
	 if(argc != 3){
		 printf("Molq vuvedete samo 2 argumenta");
		 exit(1);
	 }
	 
	 if((from = fopen(argv[1],"r"))== NULL){
		 printf("Faila ne moje da bude nameren ili otvoren\n");
		 exit(1);
	 }
	 if((to = fopen(argv[2],"a"))== NULL){
		 printf("Faila ne moje da bude nameren ili otvoren\n");
		 printf("Iskate li da suzdadete nov fail Y or N?\n");
		 exit(1);
	 }
     while((c = fgetc(from))!=EOF){
		 fputc(c,to);
	 }
	 fclose(from);
	 fclose(to);
	 
	 
	 return 0;
 }
