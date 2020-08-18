#include<iostream>

class point
{
	double x;
	double y;
public:
	
	double  get_x() const
	{
		return x;

	}
	double  get_y() const
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
	void print() const
	{
		std::cout << x << "\t" << y << std::endl;
	}
	double distance(point other)
	{
		double x_distance = other.x - this->x;
		double  y_distance = other.y - this->y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

};
double distance(point a, point b);

void main()
{
	setlocale(LC_ALL, "");
	point A;
	A.set_x(2);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
	point B;
	B.set_x(4);
	B.set_y(5);
	std::cout << B.get_x() << "\t" << B.get_y() << std::endl;
	std::cout << A.distance(B) << std::endl;
}
double distance(point a, point b)
{
	double x_distance = a.get_x() - b.get_x();
	double y_distance = a.get_y() - b.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

}