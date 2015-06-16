#include "context.hh"
#include "Operation.hh"
#include "Calc.hh"
#include "BinOperations.hh"
#include <iostream>
#include "UnOperations.hh"
using namespace std;
int main(){
	Context context;
	context.add_op(new Plus());
	context.add_op(new Minus());
	context.add_op(new Square());
	context.add_op(new Sqrt());
	context.add_op(new Swap());
	/*context.add_op(new Multiply());
	context.add_op(new Divide());*/
	Calc calc(context,cin);
	calc.run();


	return 0;
}
