#include<stdio.h>

void hello(char a){
	printf("Hello World %c \n", a);
}

void world(){
	printf("World Hello\n");
}

void calc(int a, int b, int (*op)(int, int)){
	int result = op(a, b);
	printf("Result = %d\n", result);
}

int sum(int a, int b){
	return a + b;
}

int mul(int a, int b){
	return a * b;
}

int main(){
	calc(5, 4, sum);
	calc(5, 4, mul);
	/*void (*fp)(char) = hello;
	fp('h');
	fp = world;
	fp();*/
	return 0;
}
