#include <iostream>

class Point {
	double x_,y_;
public:
	Point(double x, double y)
		:x_(x) , y_(y)
	{}

};

class Rectangle{
	Point ul_, br_ ;
public:
	Rectangle(double x, double y, double w ,double h)
		: ul_(x,y) , br_(x+w,y+h)
	{}


};

int main(){

	return 0;
}