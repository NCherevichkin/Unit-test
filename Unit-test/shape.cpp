#include "shape.h"
#include "box.h"
#include "ball.h"
#include "tetrahedron.h"

namespace simple_shapes
{
	void shape::InData(ifstream &ifst)
	{
		ifst >> temperature;
	}

	void shape::Out(ofstream &ofst)
	{
		ofst << ", melting point = " << temperature << "°C, V = " << V() << endl;
	}

	shape* shape::In(ifstream &ifst)
	{
		shape *sp;
		int k;
		ifst >> k;
		switch (k)
		{
		case 1:
			sp = new box;
			break;
		case 2:
			sp = new ball;
			break;
		case 3:
			sp = new tetrahedron;
			break;
		default:
			return 0;
		}
		sp->InData(ifst);
		return sp;
	}

	bool shape::Compare(shape &other)
	{
		return V() < other.V();
	}

	void shape::OutBalls(ofstream &ofst) { ofst << endl; }
}
