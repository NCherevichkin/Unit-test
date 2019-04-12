#include "box.h"

namespace simple_shapes
{
	void box::Out(ofstream &ofst)
	{
		ofst << "It is Box: x = " << x << ", y = " << y << ", z = " << z;
		shape::Out(ofst);
	}

	box::box(int x, int y, int z, int temperature)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		shape::temperature = temperature;
	}

	void box::InData(ifstream &ifst)
	{
		try
		{ 
			ifst >> x >> y >> z;
			
			if (x <= 0 || y <= 0 || z <= 0)
				throw exception("Стороны паралелепипеда должны быть положительными! Работа программы прекращена.");
			shape::InData(ifst);
		}
		catch (exception& except)
		{
			cout << except.what() << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
		
		
	}

	string box::ToString()
	{
		return to_string(x) + " " + to_string(y) + " " + to_string(z) + " " + to_string(temperature);
	}

	double box::V()
	{
		return x * y * z;
	}
}