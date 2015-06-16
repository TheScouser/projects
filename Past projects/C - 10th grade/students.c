#include<stdio.h>
#include<stdlib.h>

struct student{
	char *name;
	int number;
};

struct class{
	char *name;	
	struct student *st_array; // pointer of array of students
	int size; // All students free places
	int current_size; // Occupied places
};

struct student make_student(char name[100], int number){
	struct student st;
	st.name = name;
	st.number = number;
	return st;
}

struct class make_class(char name[100], int length){
	struct class cl;
	cl.name = name;
	cl.st_array = malloc(sizeof(struct student) * length);
	cl.size = length;
	cl.current_size = 0;
	return cl;
}

void add_to_class(struct class* cl, struct student st){
	if(cl->current_size < cl->size){	
		cl->st_array[cl->current_size] = st;
		cl->current_size++;
	}else{
		printf("You overflow student size of this class!\n");
	}
}

void print_class(struct class cl){
	int i;
	for(i=0; i < cl.current_size; i++){
		printf("%d %s\n", cl.st_array[i].number, cl.st_array[i].name);
	}
}

int main(){

	// Input from user
	// Sort this students by number
	// Subjects and marks
	struct student st1 = make_student("Ivan", 1);
	struct student st2 = make_student("Pesho", 2);
	struct student st3 = make_student("Tosho", 3);
	struct student st4 = make_student("Gosho", 4);
	struct class cl = make_class("10 V", 3);
	add_to_class(&cl, st1);
	add_to_class(&cl, st2);
	add_to_class(&cl, st3);
	add_to_class(&cl, st4);
	print_class(cl);

	// You need to free used memory
	return 0;
}
