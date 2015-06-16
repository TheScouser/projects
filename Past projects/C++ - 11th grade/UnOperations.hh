#ifndef UN_OPERATIONS_HH__
#define UN_OPERATIONS_HH__
#include <math.h>
#include "Operation.hh"

class UnOperation: public Operation {

public:
	UnOperation(const std::string& name);
	void calc(Context& context) const;

	virtual double un_op(double v) const = 0;

};

class Square: public UnOperation{
public:
	Square()
	:UnOperation("sq")
	{}

	double un_op(double v) const {
		return v*v;
	}
};

class Sqrt : public UnOperation {
public:
	Sqrt()
	: UnOperation("sqrt")
	{}

	double un_op(double v) const {
		return sqrt(v);
	}
};




#endif
