#include<iostream>
using namespace std;
class String
{
	int size;
	char* str;
public:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "defoltconstructor" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};

	}
	//operators:
	String& operator= (const String& other)
	{
		delete
	}
};

String::String()
{
}

String::~String()
{
	delete[] str;
	cout << "destructor:\t" << this << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	String str = "hello";
	str.print();
	str = str;
	str.print();

}