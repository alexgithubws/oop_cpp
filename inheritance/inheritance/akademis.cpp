#include <iostream>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned get_age()const
	{
		return age;
	}
	//constructors
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		this->last_name = last_name;
		this->first_name = first_name;
		this->age = age;
		cout << "hconstrctor :  " << this << endl;
	}
	virtual~Human()
	{
		cout << " hdestructor :  " << this << endl;
	}
	// methods:
	virtual void print()
	{
		cout << last_name << "  " << first_name << "  " << age << " let." << endl;
	}

	
};
class Student : public Human
{
	string specialty;
	string group;
	unsigned int rating;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_group()const
	{
		return group;
	}
	unsigned int get_rating()const
	{
		return rating;
	}
	//constructors
	Student(const string& last_name, const string& first_name, unsigned int age,
		const string& specalty, const string& group, unsigned int rating
	):Human(last_name,first_name,age)
	{
		this->specialty = specalty;
		this->group = group;
		this->rating = rating;
		cout << "sconstructor:  " << this << endl;
	}
	~Student()
	{
		cout << "sdestructor:  " << this << endl;
	}
	//method:
	void print()
	{
		Human::print();
		cout << specialty << "  " << group << " " << rating << "%\n";
	}
};
class Teacher : public Human
{
	string specialty;
	unsigned int experience;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	//constructor
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience)
		:Human(last_name, first_name, age)
	{
		this->specialty = specialty;
		this->experience = experience;
		cout << "tconstructor:  " << this << endl;
	}
	~Teacher()
	{
		cout << "tdestructor:  " << this << endl;
	}
	// methods:
	void print()
	{
		Human::print();
			cout << specialty << "opyt prepodavaniya " << experience << " let\n";
	}
};
class Graduate : public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()const
	{
		return diploma_theme;
	}
	// constructors:
	Graduate
	(const string& last_name, const string& first_name, unsigned int age,
		const string& specalty, const string& group, unsigned int rating,
		const string& diploma_theme)
	 : Student(last_name, first_name, age,specalty, group, rating)
	{
		this->diploma_theme = diploma_theme;
		cout << "gconstructor:  " << this << endl;
	}
	~Graduate()
	{
		cout << "Gdestructor:  " << this << endl;
	}
	//methods:
	void print()
	{
		Student::print();
		cout << "tema diploma:  " << diploma_theme << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Human human("tupenko", " Vasiliy", 18);
	human.print();
	Human* academiya[] =
	{
		new Student("tupenko", " Vasiliy", 18,"sety i system administrator","spu-911",85),
		new Teacher("Mirk", "Bill",45,"specialis seti", 50)
	};
	for (int i = 0; i < size(academiya); i++)
	{
		academiya[i]->print();
	}
	for (int i = 0; i < size(academiya); i++)
	{
		delete academiya[i];
	}
}