#include <iostream>
using namespace std;

class Person{
 int age;

public:
	Person(int age_)
	: age(age_)
	{}
	
	int get_num(){
		return age;
	}	

};



int main()
{
	Person p(12),p2(12);
	if (p == p2)
	{
		cout << "True" << endl;
	} else{
		cout << "false" << endl;
	}

	return 0;
}