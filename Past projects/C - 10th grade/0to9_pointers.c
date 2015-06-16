#include<stdio.h>

int main(){
	int i;
	int* p;
	for(i=0;i<10;i++){
		p=&i;
	printf("%d\n",*p);

}


	return 0;
}
