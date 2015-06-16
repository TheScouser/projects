#include <iostream>
using namespace std;

class Rational{
	long num_,den_;
public:
explicit	Rational(long num=0,long den = 1)
	: num_(num),den_(den)
	{}

	int get_num() const{
		return num_;
	}

	int get_den() const{
		return den_;
	}

	void set_num(long num){
		num_=num;
	}

	void set_den(long den){
		den_=den;
	}

	long gcd(long r, long s){
		while(s!=0){
			long temp=r;
			r=s;
			s=temp%s;
		}
		return r;
	}

	void normalize(){
		long g = gcd(num_,den_);
		num_/=g;
		den_/=g;

		if (den_ < 0 ){
			num_*=-1;
			den_*=1;
		}
	}

	Rational operator+=(const Rational& other){
		Rational r;
		r.set_num(num_+=other.num_);
        r.normalize();
		return r;
	}
	Rational operator-=(const Rational& other){
        Rational r;
		r.set_num(num_-=other.num_);
        r.normalize();
		return r;
	}

	Rational operator*=(const Rational& other){
		Rational r;
		r.set_num(num_*=other.num_);
		r.set_den(den_*=other.den_);
        r.normalize();
		return r;
	}
	Rational operator/=(const Rational& other){
		Rational r;
		r.set_num(num_*=other.den_);
		r.set_den(den_*=other.num_);
        r.normalize();
		return r;
	}
};



Rational operator+(const Rational& r1,const Rational& r2){
	Rational r;

	r.set_num(r1.get_num()*r2.get_den() + r2.get_num()*r1.get_den());
	r.set_den(r1.get_den()*r2.get_den());
    r.normalize();
	return r;

}
Rational operator-(const Rational& r1,const Rational& r2){
	Rational r;

	r.set_num(r1.get_num()*r2.get_den() - r2.get_num()*r1.get_den());
	r.set_den(r1.get_den()*r2.get_den());
	r.normalize();
	return r;
}
Rational operator*(const Rational& r1,const Rational& r2){
	Rational r;
	r.set_num(r1.get_num()*r2.get_num());
	r.set_den(r1.get_den()*r2.get_den());
	r.normalize();
	return r;
}
Rational operator/(const Rational& r1,const Rational& r2){
	Rational r;
	r.set_num(r1.get_num()*r2.get_den());
	r.set_den(r1.get_den()*r1.get_num());
	r.normalize();
	return r;
}

ostream& operator<<(ostream& out, const Rational& r){
	out << '(' << r.get_num() << '/' << r.get_den() << ')';

		return out;
}

//Aditional
bool operator==(const Rational& r1,const Rational& r2){
	if(r1.get_num() == r2.get_num() && r1.get_den() == r2.get_den()){
		return true;
	}
	return false;
}
bool operator<(const Rational& r1,const Rational& r2){
	double r1d= double(r1.get_num())/double(r1.get_den());
	double r2d = double(r2.get_num())/double(r2.get_den());

	if (r1d < r2d){
		return true;
	}
	return false;
}
bool operator>(const Rational& r1,const Rational& r2){
	double r1d= double(r1.get_num())/double(r1.get_den());
	double r2d = double(r2.get_num())/double(r2.get_den());

	if (r1d > r2d){
		return true;
	}
	return false;
}
bool operator<=(const Rational& r1,const Rational& r2){
	double r1d= double(r1.get_num())/double(r1.get_den());
	double r2d = double(r2.get_num())/double(r2.get_den());

	if (r1d <= r2d){
		return true;
	}
	return false;
}
bool operator>=(const Rational& r1,const Rational& r2){
	double r1d= double(r1.get_num())/double(r1.get_den());
	double r2d = double(r2.get_num())/double(r2.get_den());

	if (r1d >= r2d){
		return true;
	}
	return false;
}
bool operator!=(const Rational& r1,const Rational& r2){
   ;if(r1.get_num() == r2.get_num() && r1.get_den() == r2.get_den()){
		return false;
	}
	return true;
}

int main(){
	Rational r1(5,3),r2(5,3),r4(1,3);
	Rational r3;

	cout << r1 << endl;
	cout << r3 << endl;
    cout <<(r4==r1) << endl;


	//r2=5*r1;
	cout << r2 << endl;
	return 0;
}
