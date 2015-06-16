#ifndef MACRO_OPERATION_HH__
#define MACRO_OPERATION_HH__

#include <list>
#include "Operation.hh"

class MacroOperation: public Operation {
	std::list<Operation*>ops_;
public:
	MacroOperation(const std::string& name);
	void add_op(Operation* op);
	void calc(Context& context) const;

};



#endif
