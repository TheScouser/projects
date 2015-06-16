#ifndef BIN_OPERATIONS_HH__
#define BIN_OPERATIONS_HH__
#include "Operation.hh"
#include "context.hh"

class BinOperation: public Operation{

public:
	BinOperation(const std::string& name)
	: Operation(name)
	{}

	void calc(Context& context) const;
	virtual double bin_op(double v1,double v2) const =0;
};

class Plus : public BinOperation {

public:
	Plus()
	: BinOperation("+")
	{}
	double bin_op(double v1,double v2) const{
		return v1+v2;
	}
	
};

class Minus : public BinOperation {

public:
	Minus()
	: BinOperation("-")
	{}
	double bin_op(double v1,double v2) const {
		return v1-v2;
	}
	
};

class Swap: public Operation {

public:
	Swap();
	void calc(Context& context) const;


};


/*class Multiply : public Operation {

public:
	Multiply();
	void calc(Context& context) const;
	
};


class Divide : public Operation {

public:
	Divide();
	void calc(Context& context) const;
	
};
*/
#endif
