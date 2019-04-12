#include "tetrahedron.h"

namespace simple_shapes
{
	void tetrahedron::InData(ifstream &ifst)
	{
		try
		{
			ifst >> a;
			
			if (a <= 0)
				throw exception("Стороны тетраэдра должны быть положительными! Работа программы прекращена.");
			shape::InData(ifst);
		}
		catch (exception& except)
		{
			cout << except.what() << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
		
	}

	void tetrahedron::Out(ofstream &ofst)
	{
		ofst << "It is Tetrahedron: r = " << a;
		shape::Out(ofst);
	}

	tetrahedron::tetrahedron(int a, int temperature)
	{
		this->a = a;
		shape::temperature = temperature;
	}

	string tetrahedron::ToString()
	{
		return to_string(a) + " " + to_string(temperature);
	}

	double tetrahedron::V()
	{
		return  ((a * a * a * sqrt(2)) / 12);
	}
}