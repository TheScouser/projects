#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << boolalpha << true << ' ' << false << ' '
		<< noboolalpha << true << ' ' << false << endl;

	cout << showbase 
	<< hex << 1234 << " " 
	<< dec << 1234 << " " 
	<< oct << 1234 << endl;

	cout << '|' << setw(10) <<55 <<'|' << endl
		<< '|' << setw(10) << 5555 << '|' << endl;

	return 0;
}