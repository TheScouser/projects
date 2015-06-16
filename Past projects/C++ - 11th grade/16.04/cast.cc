#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	double d=42.42;
	string s;

	ostringstream out;

	out << d;

	s=out.str();

	cout << "s=" << s << endl;
	s="42.42";
	istringstream in(s);

	in >> d;
	if(!in){
		cout << "Ohh..." << endl;
		return 1;
	}
	cout << "d=" << d << endl;
	
	return 0;
}