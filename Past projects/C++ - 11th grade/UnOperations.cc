#include "UnOperations.hh"
#include <iostream>
#include "context.hh"
using namespace std;
UnOperation::UnOperation(const std::string& name)
: Operation(name)
{}

void UnOperation::calc(Context& context) const {
	if(context.empty()) {
		cerr << "Unoperation:: needs an argument..." << endl;
	} else{
		double v=context.pop();
		double res = un_op(v);
		context.push(res);
	}
}
