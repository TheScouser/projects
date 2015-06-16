#include "BinOperations.hh"
#include "context.hh"
#include <iostream>
#include "Operation.hh"
using namespace std;

void BinOperation::calc(Context& context) const{
	if(context.size()<2){
		cerr << "Need more arguments..." <<endl;
	} else{
	double v2 = context.pop();
	double v1 = context.pop();

	double res = bin_op(v1,v2);
	context.push(res);
	
	}
}

Swap::Swap()
: Operation("swap")
{}

void Swap::calc(Context& context) const {

	if(context.size() < 2) {
		cerr << "swap needs more arguments..." << endl;
	}
	else{
		double v2 = context.pop();
		double v1 = context.pop();

		context.push(v2);
		context.push(v1);
	}

}

/*Plus::Plus()
: Operation("+")
{}
Minus::Minus()
: Operation("-")
{}
Multiply::Multiply()
: Operation("*")
{}
Divide::Divide()
: Operation("/")
{}
void Plus::calc(Context& context) const{
	if(context.size()<2){
		cerr << "Need more arguments..." <<endl;
	} else{
	double v1 = context.pop();
	double v2 = context.pop();

	double res = v1+v2;
	context.push(res);
	
	}
}

void Minus::calc(Context& context) const{
	if(context.size()<2){
		cerr << "Need more arguments..." <<endl;
	} else{
	double v1 = context.pop();
	double v2 = context.pop();

	double res = v2-v1;
	context.push(res);
	
	}
}

void Multiply::calc(Context& context) const{
	if(context.size()<2){
		cerr << "Need more arguments..." <<endl;
	} else{
	double v1 = context.pop();
	double v2 = context.pop();

	double res = v1*v2;
	context.push(res);
	}
}

void Divide::calc(Context& context) const{
	if(context.size()<2){
		cerr << "Need more arguments...0" <<endl;
	} else{
	double v1 = context.pop();
	double v2 = context.pop();

	double res = v2/v1;
	context.push(res);
	}
}*/
