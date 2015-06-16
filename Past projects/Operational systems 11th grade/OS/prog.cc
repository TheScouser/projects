#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

 class Employee{
 	
 	char* firstName;
 	char* lastName;
 	int age;
 	int moneyPerHour;



 public:
 	Employee(char* firstName_,char* lastName_,int age_,int moneyPerHour_)
 	:	firstName(firstName_),
 		lastName(lastName_),
 		age(age_),
 		moneyPerHour(moneyPerHour_)
 	{}

 	int getAge() const {
 		return age;
 	}
 	char* getFirstName() const{
 		return firstName;
 	}
 	char* getLastName() const{
 		return lastName;
 	}
 	int getMoneyPerHour() const{
 		return moneyPerHour;
 	}

 	void addEmployee(Employee e){
 		vector<Employee> v;

 		v.push_back(e);
 	}

 	void print_employee(){
 		cout << firstName << " " ;
 		cout << lastName << " ";
 		cout << age << " ";
 		cout << moneyPerHour << " \n";
 	}





 };

class Company{
	vector<Employee> emp;


public:

	void print_all(){
		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
			(*it).print_employee();
		}
	}

	void create_emp(){
		for (int i = 0; i < 10; ++i){
 			Employee e1("Niki","Gei",i + 1,i + 10);
 			emp.push_back(e1);
 		}
	}

	void addEmployee(Employee e){
		emp.push_back(e);
	}

	void removeEmployee(int index){
		emp.erase(emp.begin() + index);
	}

	double averageAge(){
		double averageAge = 0;
		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
		
			averageAge +=(*it).getAge();
		}
		return averageAge/10;
	}

	double averageMoneyPerHour(){
		double averageMoneyPerHour = 0;
		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
		
			averageMoneyPerHour +=(*it).getMoneyPerHour();
		}
		return averageMoneyPerHour/10;
	}

	Employee mostPaidEmployee(){
		Employee temp=emp.back();

		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
		
			if((*it).getMoneyPerHour() > temp.getMoneyPerHour() )
			{
				temp=(*it);
			}
		}
		return temp;
	}

	Employee lessPaidEmployee(){
		Employee temp=emp.back();

		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
		
			if((*it).getMoneyPerHour() < temp.getMoneyPerHour() )
			{
				temp=(*it);
			}
		}
		return temp;
	}

	Employee youngestEmployee(){
		Employee temp=emp.back();

		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
		
			if((*it).getAge() > temp.getAge() )
			{
				temp=(*it);
			}
		}
		return temp;
	}

	Employee oldestEmployee(){
		Employee temp=emp.back();

		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
		
			if((*it).getAge() < temp.getAge() )
			{
				temp=(*it);
			}
		}
		return temp;
	}


	void printToFile(char* name){
		ofstream myfile;
		myfile.open(name);
		int i=0;
		for(vector<Employee>::iterator it=emp.begin(); it!=emp.end(); it++){
			myfile << i << " " << (*it).getFirstName() << " " << (*it).getLastName() << " " << (*it).getAge() <<" " << (*it).getMoneyPerHour() << endl;
			i++;
		}
		myfile.close();

	}
};



 int main()
 {
 	Employee e("niki","gei",0,0);
 	Company c;
 	c.create_emp();
 	// c.print_all();
 	// cout << c.averageAge() << endl;
  // 	cout << c.averageMoneyPerHour() << endl;
 	// c.addEmployee(c.youngestEmployee());
 	// c.addEmployee(c.oldestEmployee());
 	// c.print_all();
 	c.printToFile("/home/edward/OS/example.txt");
 	c.addEmployee(c.mostPaidEmployee());
 	c.print_all();

 	


 	return 0;
 }