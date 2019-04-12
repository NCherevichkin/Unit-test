#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include <iostream>
#include "shape.h"

namespace simple_shapes
{
	class tetrahedron : public shape
	{
	public:
		int a;
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		string ToString();
		double V();
		tetrahedron() {};
		tetrahedron(int radius, int temperature);
		~tetrahedron() {};
	};
}
#endif