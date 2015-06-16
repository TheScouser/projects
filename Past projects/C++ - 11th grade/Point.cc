#include "Point.hh"

Point::Point(double x,double y)
: x_(x), y_(y)
{}

std::ostream& operator<<(std::ostream& out,const Point& p){
	out << '(' << p.get_x() << ',' << p.get_y() << ')';
	return out;
}

int main()
{
	
	return 0;
}