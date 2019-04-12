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
		ifst >> x >> y >> z;
		shape::InData(ifst);
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