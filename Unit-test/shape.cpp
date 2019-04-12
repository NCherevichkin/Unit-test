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

		try
		{
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
				throw exception("Во входном файле присутствует неопознанная фигура! Работа программы прекращена.");
			}
			sp->InData(ifst);
			return sp;
		}
		catch (exception& except)
		{
			cout << except.what() << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	}

	bool shape::Compare(shape &other)
	{
		return V() < other.V();
	}

	void shape::OutBalls(ofstream &ofst) { ofst << endl; }
}
