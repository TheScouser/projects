#include "MacroOperation.hh"
#include "context.hh"
using namespace std;
MacroOperation::MacroOperation(const string& name)
: Operation(name)
{}

void MacroOperation::add_op(Operation* op){
	ops_.push_back(op);
}
void MacroOperation::calc(Context& context) const{
	for(list<Operation*>::const_iterator it= ops_.begin(); it!=ops_.end();++it) {
		(*it)->calc(context);	
}
}
