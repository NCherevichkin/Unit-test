#include "tetrahedron.h"

namespace simple_shapes
{
	void tetrahedron::InData(ifstream &ifst)
	{
		ifst >> a;
		shape::InData(ifst);
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