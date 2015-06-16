#include <stdio.h>
#include <stdlib.h>
struct point{
	int x;
	int y;
};
struct rectangle{
	
	struct point pt1;
	struct point pt2;
};

struct rectangle* make_rect(struct point pt1,struct point pt2){
	struct rectangle* temp;
	temp = malloc(sizeof(struct rectangle));
	temp->pt1=pt1;
	temp->pt2=pt2;
	return temp;
};





int main(){
	struct point pt1;
	printf("Vuvedete x na purvata tochka: \n");
	scanf("%d",&pt1.x);
	printf("Vuvedete y na purvata tochka: \n");
	scanf("%d",&pt1.y);
	struct point pt2;
	printf("Vuvedete x na vtorata tochka: \n");
	scanf("%d",&pt2.x);
	printf("Vuvedete y na vtorata tochka: \n");
	scanf("%d",&pt2.y);
	
	struct rectangle* rect = make_rect(pt1,pt2);
	printf("x1=%d,y1=%d",pt1.x,pt1.y);
	printf("Rectangle x1=%d,y1=%d,x2=%d,y2=%d\n",
	rect->pt1.x,rect->pt1.y,
	rect->pt2.x,rect->pt2.y);
	
	return 0;
}
