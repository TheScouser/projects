//Programa,koqto chete niz i ako nameri interval otpechatva ostatuka ot niza

#include <stdio.h>


int main(){

	char str[80],*p;
	int i;

	printf("Vuvedete niz: \n");
	gets(str);
	p = str;

	while(*p && *p!=' ')
	{	
		p++;
	}

	printf("%s\n",p);

	return 0;
}
