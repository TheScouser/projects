#include <iostream>
using namespace std;

//DOmashno: Klas iterator za iterirane v Spisuka kato tozi ot array.cc

class ListError{};

class List{
	friend class iterator;
	struct Elem
	{
		int data_;
		Elem* next_;
		Elem* prev_;
		Elem(int data)
		: data_(data),
		next_(0),
		prev_(0)
		{}
	};
Elem* head_;
public:
	List()
	: head_(new Elem(0))

	{
		head_->next_=head_;
		head_->prev_=head_;
	}

	~List(){
		while(!empty()){
			pop_front();
		}
		delete head_;

	}
	
	bool empty() const {
		return head_->next_==head_;
	}

	void push_back(int val){
		Elem* newElem = new Elem(val);
		Elem* back = head_->prev_;

		back->next_ = newElem;
		newElem->prev_= back;

		newElem->next_=head_;
		head_->prev_=newElem;
	}

	int back() const {
		return head_->prev_->data_;
	}

	int front() const{
		return head_->next_->data_;
	}


	void push_front(int val){
		Elem* newElem = new Elem(val);
		Elem* front = head_->next_;

		head_->next_ = newElem;
		newElem->prev_= head_;

		newElem->next_ = front;
		front->prev_ = newElem;

	}

	void pop_back(){
		if(empty()){
			throw ListError();
		} else {
			Elem* back = head_->prev_;
			Elem* newBack = back->prev_;

			newBack->next_=head_;
			head_->prev_=newBack;

			delete back;
		}
	}

	void pop_front(){
		if(empty()){
			throw ListError();
		} else {
			Elem* front = head_->next_;
			Elem* newFront = front->next_;

			newFront->prev_= head_;
			head_->next_ = newFront; 

			delete front;
		}

	}



class iterator
{
	friend class List;

	Elem* current_;

	iterator(Elem* elem)
	: current_(elem)
	{}

public:

	iterator& operator++(){
		current_=current_->next_;
		return *this;
	}

	iterator operator++(int){
		iterator it=*this;
		++*this;
		return it;
	}
	int& operator*(){
		return current_->data_;
	}

	bool operator==(const iterator& other) const{
		return current_== other.current_;
	}

	bool operator!=(const iterator& other) const{
		return !operator==(other);
	}

};

iterator begin() {
	return iterator(head_->next_);
}

iterator end() {
	return iterator(head_);
}

class const_iterator
{
	friend class List;

	Elem* current_;

	const_iterator(Elem* elem)
	: current_(elem)
	{}

public:

	const_iterator& operator++(){
		current_=current_->next_;
		return *this;
	}
	const_iterator operator++(int){
		const_iterator it=*this;
		++*this;
		return it;
	}
	const int& operator*(){
		return current_->data_;
	}

	bool operator==(const const_iterator& other) const{
		return current_== other.current_;
	}

	bool operator!=(const const_iterator& other) const{
		return !operator==(other);
	}

};

const_iterator begin() const{
	return const_iterator(head_->next_);
}

const_iterator end() const{
	return const_iterator(head_);
}


List(const List& other)
: head_(new Elem(0))
{
	head_->next_=head_->prev_=head_;

	for(List::const_iterator it=other.begin();it!=other.end();it++){
		push_back(*it);
	}
}

void clear(){
	while(!empty()){
		pop_back();
	}
}

List& operator=(const List& other){
	if(this!=&other){
clear();

	for(List::const_iterator it=other.begin();it!=other.end();++it){
		push_back(*it);
	}

	return *this;

	}
}

void insert(iterator it,int val){
	Elem* newElem = new Elem(val);
	newElem->data_=val;
		
	it.current_->prev_->next_=newElem;
	newElem->prev_=it.current_->prev_;
		
	newElem->next_=it.current_;
	it.current_->prev_=newElem;

}

void erase(iterator it){
	
	it.current_->prev_->next_=it.current_->next_;
	it.current_->next_->prev_=it.current_->prev_;
	delete it.current_;

}

void erase(iterator begin,iterator end){

	if(begin==head_->next_ && end==head_){
		clear();
		return;
	}
	if(end==head_){
		end.current_=end.current_->prev_;
	}
	while(begin!=end){
		List::iterator temp=begin;
		begin++;
		erase(temp);
	
	}

}

};

int main()
{
	/* Domashno:
	
	++it

	it++

	void insert(iterator it,int val); Dobavq nov element sus stoinost val predi elementa kum koito e nasochen iteratora!
	void erase(iterator it); Trqbva da iztrie elementa kum koito e nasochen iteratora it! i ne trqbva da se trie HEAD-a!
	void erase(iterator begin,iterator end); i trqbva da iztrie elementite mejdu begin i end vkluchitelno begin no bez end!
	erase(being(),end()); <=> clear();
	*/
	

	List l;
	
	cout << "l.empty()=" << l.empty() << endl;
	l.push_back(1);
	l.push_back(2);
	cout << "l.empty()=" << l.empty() << endl;
	l.push_front(3);
	cout << "l.back()=" << l.back() << endl;
	l.pop_front();
	cout << "l.front()=" << l.front() << endl;
	l.push_back(34);
	l.push_back(35);
	
// for (List::iterator it=l.begin();it!=l.end(); it++)
// {
// 	cout << (*it) << endl;
// }
	List l1 = l;
	List::iterator it_test=l1.begin();
	it_test++;
	List::iterator it_test2=l1.begin();
	it_test2++;
	it_test2++;
	it_test2++;
// 	for (List::iterator it=l1.begin();it!=l1.end(); ++it)
// {
// 	cout << (*it) << endl;
// }	


	l.push_back(42);

	l1=l;
	// for (List::iterator it=l1.begin();it!=l1.end(); ++it)
	// {
	// 	cout << (*it) << endl;
	// }	

	l1=l1;

	cout << "l1....................." << endl;
	for (List::iterator it=l1.begin();it!=l1.end(); ++it)
	{
		cout << (*it) << endl;
	}
	
	l1.erase(it_test,it_test2);
	for (List::iterator it=l1.begin();it!=l1.end(); ++it)
	{
		cout << (*it) << endl;
	}
// 	const List l2=l;
// for (List::iterator it=l2.begin();it!=l2.end(); ++it)
// {
// 	*it=5;
// 	cout << (*it) << endl;
// }	
	return 0;
}
// Iteratora trqbva da e constanten i da se zabrani promqnata na stoinostite prez nego!