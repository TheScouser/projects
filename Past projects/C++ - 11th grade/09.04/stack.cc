#include <iostream>
using namespace std;

class StackError{};

template<typename T>
class Stack{
	static const int CHUNK=2;
	int size_;
	int top_;
	T* data_;

	bool full() const{
		return top_==size_;
	}

	void resize(){
		cout << "Stack::resize() called..." << endl;
		T* oldData=data_;
		size_+=CHUNK;
		data_=new T[size_];

		for (int i = 0; i < top_; ++i)
		{
			data_[i]=oldData[i];
		}
		delete [] oldData;
	}

public:
	
	Stack()
	:	top_(0),
		size_(CHUNK),
		data_(new T[size_])
	{}
	
	~Stack() {
		delete [] data_;
	}

	bool empty() const{
		return top_==0;
	}

	void push(T val){
		if(full()){
			resize();
		}
		data_[top_++]=val;
	}

	T pop(){
		if(empty()){
			throw StackError();
		}
		return data_[--top_];
	}

	int capacity() const;

	Stack& operator=(const Stack& other);
	Stack(const Stack& other);
};

template<typename T>
int Stack<T>::capacity() const{
	return size_;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
	if(this!=&other){
		delete [] data_;
		size_=other.size_;
		top_=other.top_;
		data_=new T[size_];

		for (int i = 0; i < top_; ++i)
		{
			data_[i]=other.data_[i];
		}
	}
	return *this;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other){
	size_=other.size_;
		top_=other.top_;
		data_=new T[size_];

		for (int i = 0; i < top_; ++i)
		{
			data_[i]=other.data_[i];
		}
}


int main()
{
	Stack<int> st1;
	Stack<double> st2;
	cout << st1.empty() << endl;
	cout << st2.empty() << endl;
	st1.push(10);
	st2.push(3.14);
	cout << st1.empty() << endl;
	cout << st2.empty() << endl;
	cout << "st1.pop" << st1.pop() << endl;
	cout << "st2.pop" << st2.pop() << endl;
	cout << st1.empty() << endl;
	cout << st2.empty() << endl;


	for (int i = 0; i < 10; ++i)
	{
		st1.push(i);
		st2.push(i*3.14);
	}

	Stack<int> st3(st1);
	Stack<double> st4;
	
	st4=st2;
	cout << st3.empty() << endl;
	cout << st4.empty() << endl;


	return 0;
}
