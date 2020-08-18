#include<iostream>
using std::cin;
using std::cout;
using std::endl;



class String;
String operator+(const String& left, const String& right);
class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return this->size;
	}
	const char* get_str()const
	{
		return this->str;
	}
	char* get_str()
	{
		return str;
	}
	//constructor
	explicit String(int size = 100)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{

		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;

	}

	const char& operator[](int index)const
	{
		return str[index];
	}

	char& operator[](int index)
	{
		return str[index];
	}
	//   metods:
	void print()const
	{
		cout << "size : " << size << endl;
		cout << "str : " << str << endl;
	}




};
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		result[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		result[i + left.get_size() - 1] = right[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	return is >> obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;

	String str4;
	cout << "¬ведите строку: "; cin >> str4;
	cout << str4 << endl;
}