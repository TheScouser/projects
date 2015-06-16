
#ifndef OPERATION_HH__
#define OPERATION_HH__ 
#include <string>
class Context;

class Operation
{
	std::string name_;
public:
	virtual void calc(Context& context) const = 0;

	Operation(const std::string& name)
	: name_(name)
	{}
	std::string get_name() const {return name_;}
	

};


#endif