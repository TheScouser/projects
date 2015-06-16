#include <iostream>
using namespace std;


class Point{
	double x_,y_;
public:
	Point(double x=0.0,double y=0.0)
	:	x_(x), y_(y)
	{}

	double get_x()const {
		return x_;
	}

	double get_y() const{
		return y_;
	}

	Point& set_x(double x){
		x_=x;
		return *this;
	}
	
	Point& set_y(double y){
		y_=y;
		return *this;
	}
};

ostream& operator<<(ostream& out,const Point& p){
	out << '(' << p.get_x() << ',' << p.get_y() << ')';
	return out;
}
istream& operator>>(istream& in,Point& p){
	double x,y;
	char c;

	in >> c;
	if(c!= '('){
		in.clear(ios_base::badbit);
		return in;
	}

	in >> x >> c;
	if(c!=','){
		in.clear(ios_base::badbit);
		return in;
	}
	in >> y >> c;
	if(c!=')'){
		in.clear(ios_base::badbit);
		return in;
	}
	if(in.good()){
		p.set_x(x).set_y(y);
	}
	return in;


}


int main()
{
	Point p1(10,20),p2(30,40);
	cout << p1 << p2 << endl;

	while(true){
		cin >> p1;
		if(!cin){
			cout << "Ohh..." << endl;
			break;
		}
		cout << p1 << endl;
	}

	return 0;
}