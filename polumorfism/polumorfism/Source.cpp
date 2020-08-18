#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "animalconstructor:\t" << this << endl;
	}
	virtual~Animal()
	{
		cout << "animaldestructor:\t" << this << endl;
	}
	virtual void sound() = 0;
	
};
class Cat :public Animal 
{
public:
	Cat()
	{
		cout << "catconstructor:\t" << this << endl;
	}
	~Cat()
	{
		cout << "catdestructor:\t" << this << endl;
	}
	
	void sound()
	{
		cout << " mau.. " << endl;
	}
};
class Dog : public Animal
{
public:
	Dog()
	{
		cout << "dogconstructor:\t" << this << endl;
	}
	~Dog()
	{
		cout << "dogdestructor:\t" << this << endl;
	}
	void sound()
	{
		cout << "wof... " << endl;
	}
	
};




void main()
{
	setlocale(LC_ALL, "");

	Animal* yard[] =
	{
		new Cat{},
		new Dog{}
	};
	for (int i = 0; i < size(yard); i++)
	{
		yard[i]->sound();
	}
	for (int i= 0; i < size(yard); i++)
	{
		delete yard[i];
	}
}