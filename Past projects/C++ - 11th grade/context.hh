#ifndef CONTEXT_HH__

#define CONTEXT_HH__

#include <list>
#include <string>
#include "Operation.hh"
class Context
{
	std::list<double> stack_;
	std::list<Operation*> ops_;
public:
	
	void push(double val);
	double pop(void);
	double top()const;
	bool empty() const;
	int size() const;
	void add_op(Operation* op);
	Operation* find_op(const std::string& name) const;
};

#endif