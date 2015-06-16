#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	if(argc!=3){
		cerr << "wrong number of arguments..." << endl;
		return 1;
	}

	ifstream from(argv[1]);
	if(!from){
		cerr << "bad input file..." << endl;
		return 1;
	}

	ofstream to(argv[2]);
	if(!to){
		cerr << "bad output file..." << endl;
		return 1;
	}

	char ch;
	while(from.get(ch)){
		to.put(ch);
	}
	if(!from.eof() || !to){
		cerr << "strange error..." << endl;
		return 1;
	}


	return 0;
}