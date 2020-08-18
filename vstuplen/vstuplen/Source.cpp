#include<iostream>

using namespace std;


class Point
{

	double x;
	double y;
public:
	double get_x() const
	{
		return x;

	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	Point()
	{
		cout << "distrakt"<<this;

	}
	~Point()
	{
		cout << "distrakt" << this;
	}
};
#define structure
void main()
{
	setlocale(LC_ALL, "");
/*#ifdef structure
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y;
	cout << (*pA).x << "\t" << (*pA).y;
#endif // DEBUG*/
	Point A;
	/*A.set_x (2);
	A.set_y (3);*/
	cout << A.get_x() << "\t" << A.get_y()<<endl;
	
}