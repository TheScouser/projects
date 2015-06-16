#ifndef CALC_HH__
#define CALC_HH__ 
#include <iostream>
#include "context.hh"
#include <string>
class Calc
{
	Context& context_;
	std::istream& in_;
	void macro_definition(const std::string& name);

public:
	Calc(Context& context,std::istream& in);
	
	void run();
};

#endif
