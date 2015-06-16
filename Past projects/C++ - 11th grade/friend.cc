#include <iostream>
using namespace std;
class Point{
	friend void print(Point& p);
	double x_, y_;
public:
	Point(double x, double y)
	:x_(x), y_(y)
	{}
};

class Rectangle{
    friend void print(Rectangle& r);
	Point ul_, br_ ;
public:
	Rectangle(double x, double y, double w ,double h)
		: ul_(x,y) , br_(x+w,y+h)
	{}

void print(Point& p){
	cout << '(' << p.x_ << "," << p.y_ << ")";
}

void print(Point& p1, Point& p2){
	print(p1);
	print(p2);
}

void print(Rectangle& r){
    print(r.ul_, r.br_);
}

int main(){
    Point p1(10,10), p2(20,20);

    print(p1);
    print(p2);
    cout << endl;
    print(p1,p2);
    cout << endl;
    Rectangle r(10,10,20,20);
    print(r);

	return 0;
}
