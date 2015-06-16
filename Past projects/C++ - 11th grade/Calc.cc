#include "Calc.hh"
#include "context.hh"
#include "Operation.hh"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "MacroOperation.hh"
using namespace std;

Calc::Calc(Context& context,istream& in)
: context_(context),
  in_(in)
  {}

void Calc::macro_definition(const string& name){
	MacroOperation* macro = new MacroOperation(name);

string token;

	in_>>token;
	while(in_) {
		if(token=="def"){
			break;
			
		}
		else{
		Operation* op=context_.find_op(token);
		if (op!=NULL){
			macro->add_op(op);
		} else{
			istringstream istr(token);
			double val=0.0;
			istr>>val;
			if(istr){
				// ??

			}
			else if(token == "exit"){ exit(1);}
			else{
				cerr << "UNKOWN TOKEN: <" << token << ">" << endl;
			}
		}
		}
		in_>>token;
	}
	
	context_.add_op(macro);


}

void Calc::run(){
	string token;

	in_>>token;
	while(in_) {
		if(token[0]=='/'){
			//macro definition!!
			macro_definition(token.substr(1));
		}
		else{
		Operation* op=context_.find_op(token);
		if (op!=NULL){
			op->calc(context_);
			cout << ">" << context_.top() << endl;
		} else{
			istringstream istr(token);
			double val=0.0;
			istr>>val;
			if(istr){
				context_.push(val);

			}
			else if(token == "exit"){ exit(1);}
			else{
				cerr << "UNKOWN TOKEN: <" << token << ">" << endl;
			}
		}
		}
		in_>>token;
	}
}
