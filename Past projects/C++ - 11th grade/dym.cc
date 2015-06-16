#include <cstdlib>
#include <iostream>
using namespace std;

class Foo{
	int a_;
public:
	Foo()
	: a_(42)
	{}

	Foo(int a)
	: a_(a)
	{}

	Foo(int a,int b)
	: a_(a+b)
	{}

	int get_a() const {
		return a_;
	}
};

int main()
{
	Foo f;

	cout << "a=" << f.get_a() << endl;
	Foo* pf= (Foo*) malloc(sizeof(Foo));//malloc ne razbira ot konstruktori
	cout << "a=" << pf->get_a() << endl;
	free(pf);


	Foo* pf1 = new Foo;
	cout << "a=" << pf1->get_a() << endl;
	delete pf1;

	Foo* pf2 = new Foo(43);
	cout << "a=" << pf2->get_a() << endl;
	delete pf2;

	Foo* pf3 = new Foo(43,3);
	cout << "a=" << pf3->get_a() << endl;
	delete pf3;

	Foo* pf4 = new Foo[100]; // zaduljitelno konstruktor po podrazbirane
	cout <<"a=" << pf4[0].get_a()<< endl;
	delete [] pf4; // masiv se osvobojdava s delete[]


	return 0;
}