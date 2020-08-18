#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;	
	int numerator;	
	int denominator;
public:
	int get_integer()const
	{
		return this->integer;
	}
	int get_numerator()const
	{
		return this->numerator;
	}
	int get_denominator()const
	{
		return this->denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}


	//			Constructors:
	Fraction()
	{
		integer = numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other; //ошибка как ьисправить
	}

	//		Increment/Decrement:
	Fraction& operator++()	//Prefix increment
	{
		this->integer++;
		return *this;
	}
	Fraction& operator--()	//Prefix increment
	{
		this->integer--;
		return *this;
	}
	Fraction operator++(int)//Suffix increment
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}
	Fraction operator--(int)//Suffix increment
	{
		Fraction old = *this;
		this->integer--;
		return old;
	}

	//			Type-cast operators:
	operator int()const
	{
		return integer;
	}
	operator char()const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	operator float()const
	{
		return integer + (double)numerator / denominator;
	}

	//			Methods:
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& reduce()
	{
		return *this;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res.to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_numerator());
	return res.to_proper();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator()*right.get_denominator()+right.get_numerator()*left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res.to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res.to_proper();
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) cout << 0;
	return os;
}

inline bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}

bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}

//#define CONSTRUCTORS_CHECK
//#define OPERATORS_CHECK
#define TYPE_CONVERSIONS

void main()
{
#ifdef CONSTRUCTORS_CHECK
	Fraction A;	//Default constructor
	A.print();
	unsigned long b = 5.2;
	Fraction B = b;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(3, 4, 5);
	D.print();
	Fraction E = D;	//CopyConstructor
	E.print();
	Fraction F;
	F = E;	//CopyAssignment  
#endif // CONSTRUCTORS_CHECK


	Fraction A(1, 2, 3);
	Fraction B(4, 5, 6);
	Fraction C = A / B;
	C.print();
	//A *= B;
	B = A++;
	A.print();
	B.print();
	cout << A << endl;
	cout << (A != B) << endl;

	




	
	
}
