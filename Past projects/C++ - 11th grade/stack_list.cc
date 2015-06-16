#include <list>
#include <iostream>
using namespace std;

class StackError{
        int error_code_;
public:
        StackError(int error_code){
            error_code_ = error_code;

        }
        int get_error_code(){
            return error_code_;

        }
};

class Stack{
	list<int> data;

public:
	void push(int v){
		data.push_front(v);
	}

	int pop(){
		if (data.empty())
		{
			throw StackError(1);
		}
		int temp = data.front();
        data.pop_front();
        return temp;
	}

};


 int main(){
	Stack st;


	st.push(1);
	st.push(4);
	st.push(12);


try{
    cout << "Element: " << st.pop() << endl;
    cout << "Element: " << st.pop() << endl;
    cout << "Element: " << st.pop() << endl;
    cout << "Element: " << st.pop() << endl;
} catch(StackError ex){
    cout << "Smart handling of empty stack..." << endl;
    cout << "Error code: " << ex.get_error_code() << endl;
}
    return 0;
}
