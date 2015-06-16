#include <stdio.h>
#include <stdlib.h>

// Declare types

struct struct_example{
	char symbol1;
	char symbol2;
	char symbol3;
	int number1;
	int number2;
	int number3;
};

union union_example{
	char symbol1;
	char symbol2;
	char symbol3;
	int number1;
	int number2;
	int number3;
};

typedef struct {
	char symbol1;
	char symbol2;
	char symbol3;
	int number1;
	int number2;
	int number3;
} S_Example;

typedef union {
	char symbol1;
	char symbol2;
	char symbol3;
	int number1;
	int number2;
	int number3;
} U_Example;

int main()
{	
	// Declare vars
	struct struct_example s_example;
	union union_example u_example;
	typedef struct struct_example S_Example2;
	typedef union union_example U_Example2;
	
	// Print size vars
	printf("struct bytes: %d\n", sizeof(s_example));
	printf("union bytes: %d\n", sizeof(u_example));
	
	printf("\n");
	// Examples with unions
	u_example.symbol1 = 'a';
	printf("1. u_example.symbol1 = %c\n", u_example.symbol1);
	u_example.symbol2 = 'b';
	printf("2. u_example.symbol1 = %c\n", u_example.symbol1);
	u_example.symbol3 = 'c';
	printf("3. u_example.symbol1 = %c\n", u_example.symbol1);
	u_example.number1 = 1000;
	printf("4. u_example.symbol1 = %d\n", u_example.symbol1);
	
	printf("\n");
	// Examples with void pointer
	void* void_pointer;
	printf("1. void_pointer = %p\n", void_pointer);
	void_pointer = NULL;
	printf("2. void_pointer = %p\n", void_pointer);
	
	
	int int_example = 5;
	void_pointer = &int_example;
	printf("3. int_example = %d\n", *((int*)void_pointer));
	
	s_example.symbol1 = 'a';
	s_example.symbol2 = 'b';
	s_example.number1 = 1000;	
	void_pointer = &s_example;
	struct struct_example * struct_pointer = void_pointer; 

	printf("4. struct_pointer = %p, void_pointer = %p\n",struct_pointer, void_pointer);
	printf("5. s_pointer.symbol1 = %c, s_pointer.symbol2 = %c, s_pointer.number1 = %d\n",
	struct_pointer->symbol1,
	struct_pointer->symbol2,
	struct_pointer->number1);
	
	return 0;
}
