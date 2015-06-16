#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct car{
	char *name;
	int year;
	float razhod;
};

struct salon{
	char *name;	
	struct car *car_array; // pointer of array of students
	int size; // All students free places
	int current_size; // Occupied places
};

struct car make_car(char name[10], int year, float razhod){
	struct car c;
	c.name = name;
	c.year = year;
	c.razhod = razhod;
	return c;
}

struct salon make_salon(char name[10], int length){
	struct salon s;
	s.name = name;
	s.car_array = malloc(sizeof(struct car) * length);
	s.size = length;
	s.current_size = 0;
	return s;
}
void car_delete(struct salon* s,int number){
	s->car_array[number].razhod = 0.0;
	s->car_array[number].year = 0;
	s->car_array[number].name = 0;
}
	
void add_to_salon(struct salon* s, struct car c){
	if(s->current_size < s->size){	
		s->car_array[s->current_size] = c;
		s->current_size++;
	}else{
		printf("You overflow car size of this salon!\n");
	}
}

void print_salon(struct salon s){
	int i;
	for(i=0; i < s.current_size; i++){
		printf("Godina: %d; Marka: %s; Benzin na 100 km: %f\n", s.car_array[i].year, s.car_array[i].name, s.car_array[i].razhod);
	}
}
void spravka(struct salon *s, int y){
	int i;
	for (i=0; i<s->current_size; i++){
		if (y>s->car_array[i].year) {
			printf("%d %s %f\n", s->car_array[i].year, s->car_array[i].name, s->car_array[i].razhod);
		}
	}
}
int main(){

	
	struct car c1 = make_car("opel", 1990, 7.8);
	struct car c2 = make_car("audi", 2000, 8.2);
	struct car c3 = make_car("mercedes", 2009, 6.8);
	
	struct salon s = make_salon("troll", 3);
	add_to_salon(&s, c1);
	add_to_salon(&s, c2);
	add_to_salon(&s, c3);
	car_delete(&s, 2);
	spravka(&s, 2001);
	
	print_salon(s);

	sleep(6000);
	return 0;
}
