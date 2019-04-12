#ifndef SHAPE_H
#define SHAPE_H

#include <fstream>
#include <string>

using namespace std;

namespace simple_shapes
{
	class shape
	{
	public:
		int temperature;
		static  shape* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;
		virtual void Out(ofstream &ofst) = 0;
		virtual string ToString() = 0;
		virtual double V() = 0;
		virtual void OutBalls(ofstream &ofst);
		bool Compare(shape &other);
	};
}
#endif