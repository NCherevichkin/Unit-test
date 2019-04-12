#include "ball.h"

namespace simple_shapes
{
	void ball::InData(ifstream &ifst)
	{
		ifst >> radius;
		shape::InData(ifst);
	}

	void ball::Out(ofstream &ofst)
	{
		ofst << "It is Ball: r = " << radius;
		shape::Out(ofst);
	}

	void ball::OutBalls(ofstream &ofst)
	{
		Out(ofst);
	}

	ball::ball(int radius, int temperature)
	{
		this->radius = radius;
		shape::temperature = temperature;
	}

	string ball::ToString()
	{
		return to_string(radius) + " " + to_string(temperature);
	}

	double ball::V()
	{
		return  ((radius * radius * radius * 3.14 * 4) / 3);
	}
}