#ifndef BOX_H
#define BOX_H
#include <iostream>
#include "shape.h"

namespace simple_shapes
{
	class box : public shape
	{
	public:
		int x, y, z;
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		string ToString();
		double V();
		box() {};
		box(int x, int y, int z, int temperature);
		~box() {};
	};
}
#endif