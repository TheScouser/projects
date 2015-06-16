#include <iostream>
#include <list>
using namespace std;

class Shape
{
public:
	virtual void draw() const = 0;

	 // void draw() const {
	 // 	cout << "Shape::draw()" << endl;
	 // }
};

class Point
{
	double x_,y_;
public:
	Point(double x = 0 , double y = 0)
	: x_(x),y_(y)
	{}

	double get_x()const{
		return x_;
	}
	double get_y()const{
		return y_;
	}
};
ostream& operator << (ostream& out,const Point& p){
	out << '(' << p.get_x() << ',' << p.get_y() << ')';
	return out;
}

class Circle : public Shape
{
	Point c_;
	double r_;
public:
	Circle(const Point& c, double r)
	: c_(c),r_(r)
	{}

	void draw() const {
		cout << "Circle(" << c_ << ',' << r_ << ")" << endl;
	}
};

class Rectangle : public Shape
{
	Point orig_;
	double w_,h_;
public:
	Rectangle(const Point& p,double w, double h)
	: orig_(p),w_(w),h_(h)
	{}

	void draw()const {
		cout << "Rectangle(" << orig_ << ',' << w_ << ',' << h_ << ")" << endl;
	}
};

int main()
{
	//Shape* sh;
	Point p;
	cout << p << endl;

	Circle c(Point(10,20),30);
	c.draw();
	Rectangle r(Point(-10,-10),20,10);
	r.draw();

	list<Shape*> drawing;
	drawing.push_back(&c);
	drawing.push_back(&r);

	for(list<Shape*>::iterator it=drawing.begin(); it!=drawing.end(); it++){
		(*it)->draw();
	}


	return 0;
}
