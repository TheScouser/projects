#include <iostream>
using namespace std;

class StackError{};

class Stack{
	const static int CHUNK=3;
	int top_;
	int size_;
	int* data_;
public:
	Stack()
	: top_(0),
	size_(CHUNK),
	data_(new int[size_])
	{}


	~Stack() {
		cout << "~Stack called...";
		delete[] data_;
	}


	bool empty() const {
		return top_==0;
	}

	bool full() const{
		return top_==size_;
	}

	int pop(){
		if(empty()){
			throw StackError();
		}
		return data_[--top_];
	}

	void push(int val){
		if(full()){
			resize();
		}
		data_[top_++]=val;
	}

	void resize(){
		int newsize = size_+CHUNK;
		cout <<"resize() called : size= " << size_ <<  "  "  << "newsize=" << newsize << endl;
		int *temp = new int[newsize];
		for(int i = 0;i <size_;i++){
			temp[i]=data_[i];
		}

		delete[] data_;
		data_=temp;
		size_=newsize;
	}

};

int main()
{
	try{}
	Stack st;
	cout << "empty?=" << st.empty() << endl;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << "empty?=" << st.empty() << endl;
	st.push(4);
}catch (StackError ex){
	cout<<"StackError catched..." << endl;
}
	return 0;
}