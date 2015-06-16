#include <iostream>
using namespace std;

class StackError{};

class Stack{
	const static int STACK_SIZE=3;
	int top_;
	int data_[STACK_SIZE];
public:
	Stack()
	: top_(0)
	{}

	bool empty() const{
		return top_==0;
	}

	bool full() const {
		return top_==STACK_SIZE;
	}

	int pop(){
		if(empty()){
			throw StackError();
		}
		return data_[--top_];
	}

	void push(int val){
		if(full()){
			throw StackError();
		}
		data_[top_++]==val;
	}

};

int main()
{
	Stack st;

	st.push(1);
	cout << "empty?=" << st.empty() << endl;
	cout << "full?=" << st.full() << endl;
	
	st.push(2);
	st.push(3);
		cout << "empty?=" << st.empty() << endl;
	cout << "full?=" << st.full() << endl;
	return 0;
}