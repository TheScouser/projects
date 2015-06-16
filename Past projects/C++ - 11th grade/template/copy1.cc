#include <iostream>
using namespace std;


void copy1(int dst[],int src[],int size){
	for (int i = 0; i < size; ++i){
		dst[i] = src[i];
	}
}


void copy_array(void* dst,void* src,int size){
	for (int i = 0; i < size; ++i)
	{
		static_cast<char*>(dst)[i] = static_cast<char*>(src)[i]; // i-tiq bait... dst se preobrazuva kum char* i se izvurshva pobitovo kopirane
	}
}


int main(int argc, char const *argv[])
{
	int a[10],b[10];
	double c[10],d[10];
	for (int i = 0; i < 10; ++i)
	{
		a[i]=i;
	}

	copy_array(b,a,sizeof(a));

	for (int i = 0; i < 10; ++i)
	{
		cout << "b[" << i << "]=" << b[i] << endl;
	}
	for (int i = 0; i < 10; ++i)
	{
		c[i]=i*0.001;
	}

	copy_array(d,c,sizeof(c));

	for (int i = 0; i < 10; ++i)
	{
		cout << "d[" << i << "]=" << d[i] << endl;
	}


	copy_array(b,c,sizeof(c));
	copy_array(d,a,sizeof(a));

	for (int i = 0; i < 10; ++i)
	{
		cout << "b[" << i << "]=" << b[i] << endl;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << "d[" << i << "]=" << d[i] << endl;
	}

	return 0;
}