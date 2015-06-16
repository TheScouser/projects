#include<stdio.h>

struct point
{
	int x;
	int y;
};

struct rectangle
{
	struct point pt1;
	struct point pt2;
};

struct point make_point(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

struct rectangle make_rectangle(struct point pt1, struct point pt2)
{
	struct rectangle temp;
	temp.pt1 = pt1;
	temp.pt2 = pt2;
	return temp;
}

void print_point(struct point pt)
{
	printf("Point = (%d, %d)\n", pt.x, pt.y);
}

void print_rectangle(struct rectangle rect)
{
	printf("Rectangle:\n");
	print_point(rect.pt1);
	print_point(rect.pt2);
}

int is_intersect(struct rectangle rect1, struct rectangle rect2)
{
	if(rect1.pt1.x < rect2.pt2.x &&
	   rect1.pt1.y < rect2.pt2.y &&
	   rect1.pt2.x > rect2.pt1.x &&
	   rect1.pt2.y > rect2.pt1.y)
	{
		return 1;
	}
	return 0;
}

int main(){
	struct rectangle rect1 = make_rectangle(make_point(2,1), make_point(4,6));
	struct rectangle rect2 = make_rectangle(make_point(3,3), make_point(9,9));
	
	printf("Intersection: %d\n", is_intersect(rect1, rect2));
	
	return 0;
}
