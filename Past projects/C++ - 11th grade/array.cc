#include <iostream>
using namespace std;
class ArrayError
{


};


class Array{
	int capacity_;
	int size_;// size_ <= capacity_
	int *data_;
public:
	Array(int size);
	~Array(void);

	Array(const Array& other);
	Array& operator=(const Array& other);

const	int& operator[](int index) const;
		int& operator[](int index);

	int size() const{
		return size_;
	}


	void push_back(int val);
	void pop_back(void);

	int back() const;
	int front() const;
private:
	void resize();
public:

	class iterator
	{
	Array& array_;
	int pos_;

	friend class Array;
	
	iterator(Array& array,int pos)
	: array_(array),pos_(pos)
	{}
	
	public:
	iterator& operator++(){
		pos_++;
		return *this;
	}

	iterator operator++(int){
		// Homework												
	}

	int& operator*(){
		return array_[pos_];
	}
	bool operator==(const iterator& other){
		return pos_==other.pos_;
	}
	bool operator!=(const iterator& other){
		return !operator==(other);
	}
	



	};

iterator begin(){
	return iterator(*this,0);
}
iterator end(){
	return iterator(*this,size());
}

//Homework:
const_iterator begin() const;
const_iterator end()	const;

};






void Array::resize(){
	int* temp = data_;
	capacity_ *=  2;
	data_ = new int [capacity_];
	for (int i = 0; i < size_; ++i)
	{
		data_[i] = temp[i];
	}

	delete [] temp;
}


void Array::pop_back(){
	size_--;
}

void Array::push_back(int val){
	if(size_>=capacity_){
		resize();
	}
	data_[size_++]=val;

}


int Array::back()const{
	return data_[size_ - 1];
}

int Array::front() const {
	return data_[0];
}


Array& Array::operator=(const Array& other){
	if(this!=&other){
		delete[] data_;

		capacity_ = other.capacity_;
		size_ = other.size_;
		data_ = new int[size_];

		for (int i = 0; i < size_; ++i)
		{
			data_[i] = other.data_[i];
		}
	}
	return *this;
}


Array::Array(const Array& other)
:	capacity_(other.capacity_),
	size_(other.size_),
	data_(new int[capacity_])
	{
		for (int i = 0; i < size_; ++i)
		{
			data_[i] = other.data_[i];
		}

	}


Array::~Array(void){
	delete[] data_;
}


Array::Array(int size)
: 	capacity_(size),
 	size_(size),
 	data_(new int[capacity_])
 	{
 		for (int i = 0; i < size_; ++i)
 		{
 			data_[i]=0;
 		}
 	}

int& Array::operator[](int index){
	if(index<0 || index>=size_){
		throw ArrayError();
	}
	return data_[index];
}

const int& Array::operator[](int index) const{
	if(index<0 || index>=size_){
		throw ArrayError();
	}
	return data_[index];
}


void dump(const Array& a){
	for (int i = 0; i < a.size(); ++i)
{
	cout << a[i] << " ";
	
}
cout << endl;
}








int main(){
	Array a(10);



for (int i = 0; i < a.size(); ++i)
{
	a[i]=i*10;
}
// dump(a);

// Array b=a;
// dump(b);


Array c(10);

c=a;


// cout << c.back() << endl;

// cout << c.front() << endl;

c.pop_back();
dump(c);

c.push_back(42);
dump(c);


cout << "front=" << c.front() << endl;
cout << "back=" << c.back() << endl;
c.pop_back();
dump(c);


for(Array::iterator it =c.begin();it!= c.end();++it){
	cout << (*it) << endl;
}

const Array& cc= c;

for (Array::iterator it =cc.begin();it!=cc.end();++it)
{
	cout << *it << endl;
}

	return 0;
}