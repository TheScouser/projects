#include <iostream>
using namespace std;

int main()
{
	cin.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
try{
	int i;
	for(; ;){
		cin >> i;
		cout << "i=" << i << endl;
	}
} catch(ios_base::failure& ex){
	cout << "ios_base::failure caught...." << endl;
}
	
	return 0;
}